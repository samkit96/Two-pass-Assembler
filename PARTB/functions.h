#ifndef FUNCTIONS__
#define FUNCTIONS__

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Opcodes              //This node is used for Hashing using Chaining
{
        char name[10], code[35], format[5];	// Name of Opcode, Machine code of 		Opcode, Format of Opcode
        /**
        ri  = reg imm.
        rr  = reg reg
        a   = add
        z   = zero
        */
	struct Opcodes *next;
};
typedef struct Symbol_table Symbol_table;

struct Symbol_table           //Symbol_table Table is made using Linked List to save space
{
	int add;
	char name[50];
    	struct Symbol_table *next;
};

typedef struct Opcodes Opcodes;

extern Opcodes* map[];					// For hash table of opcodes with key as operation name
extern Symbol_table *head;					// For Linked list of symbols

//Functions for creating and retrieving data from hash map
int get_map_index(char Name[]);
void Insert_at_index(int idx, Opcodes*Node);
void Insert_into_map(Opcodes *Node);
Opcodes* get_Opcode_Node(char *op_name);

// During second pass we need to paste the address symbol hence a function for retrieving the address in binary format
int* get_add_from_symbol(char *label_name);

// Utility function to get bin equi of registers
char* get_register_binary(char *reg);

// First utility(8 bit) for getting values for immediate addressing and second one (10 bit) for Address type addressing
int* get_binary_conv8(int var);
int* get_binary_conv10(int var);
#endif
