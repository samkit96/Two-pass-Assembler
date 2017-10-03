#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
//returns the index of Operations in the hash map

//extern Opcodes* map[13];
//extern Symbol_table *head;

void main(int argc, char* argv[]) {

	char opcode[100],machine_ins[100],format_op[5]; // Buffers for storing
	//printf("Open input opcode\n");
	FILE *opcode_ip=fopen("../utility/op_ip.txt","r+");
	//printf("Open input opcode succesfully\n");
	char foo1,foo2,foo3;
	int ILC=0,base=0;
	//printf("hi\n");
	do {
		
		foo1=fscanf(opcode_ip,"%s",opcode);
		foo2=fscanf(opcode_ip,"%s",machine_ins);
		foo3=fscanf(opcode_ip,"%s",format_op);
		if(foo1==EOF && foo2==EOF && foo3==EOF)
			break;
		Opcodes *Node=(Opcodes*)malloc(sizeof(Opcodes));
		
		strcpy(Node->name,opcode);
		strcpy(Node->code,machine_ins);
		strcpy(Node->format,format_op);
		//Node->next=NULL;
		Insert_into_map(Node);
		//printf("inf loop");
	} while(foo1!=EOF && foo2!=EOF && foo3!=EOF);
	
	//printf("While exe\n");
	
	printf("Hash map Created Successfully!\n");
	
	Opcodes *haha;
	int q;
	for(q=0 ; q<=12 ; q++) {
	
		haha=map[q];
		printf("%d - ",q);
		while(haha!=NULL) {
			
			printf("%s::%s::%s\t",haha->name,haha->format,haha->code);
			haha=haha->next;
		}
		printf("\n");
	}
	    
	FILE *instructions_ip=fopen(argv[1],"r+");
	char op[100];
	int no_of_labels=0;
	//printf("FILE POINTER\n");
	printf("CREATING SYMBOL TABLE\n");
	while (fgets(op,sizeof op,instructions_ip)!=NULL) {		//read a line 		
		
		//printf("Line read using fgets %d\n",ILC);
		//int i;
		//printf("%lu    ",strlen(op));
		//for(i=0 ; op[i]!='\0' ; ++i)
		//	printf("%c",op[i]);
		//printf("\n");
		//printf("%d       ",ILC);
		//for(i=0 ; op[i]!='\0' ; ++i)
		//	printf("%c",op[i]);
		
		//printf("%lu \n",strlen(op));
		//printf("%c %c %c ",op[0],op[1],op[2]);
		
		//if(op[0]=='H' && op[1]=='L' && op[2]=='T') {
		
		//	printf("%c %c %c ",op[0],op[1],op[2]);
		//	break;
		//}
		int len;
		for(len=0 ; op[len]!='\0' ; ++len) {
		
			//printf("%s",op);
			//printf("%d",op[len+1]);	
			if(op[len]==':') {
			
				//printf("Label Found!\n");
				Symbol_table *tmp2;
				Symbol_table *tmp=(Symbol_table*)malloc(sizeof(Symbol_table));
				int j;
				for(j=0 ; j<len ; j++) {		// Copying Data
				
					tmp->name[j]=op[j];
				}	
				//printf("%c",op[len]);
				tmp->add=base+ILC+1-no_of_labels;
				tmp->name[j]='\0';
				tmp->next=NULL;
				//int j;
				//printf("%d  ",tmp->add);
				//for(j=0 ; j<i ; j++)
				//	printf("%c",tmp->name[j]);
				//printf("\n");
				
				if(head==NULL) {
				
					head=tmp;
				}
				else {
				
					tmp2=head;
					while(tmp2->next!=NULL) {
					
						tmp2=tmp2->next;
					}
					tmp2->next=tmp;
				}
				no_of_labels++;			
			}	
		}
		++ILC;
		//printf("%d ",ILC);
	}
	printf("PASS 1 COMPLETED SUCCESFULLY\n\nSymbol table :\n");
	FILE *fp=fopen("../utility/Symbol_table.txt","w+");	//Printing Symbol table to terminal and to the symbol table file	
	Symbol_table *print=head;
	while(print!=NULL) {
	
		printf("%s :: ",print->name);
		fprintf(fp,"%s :: ",print->name);
	        printf("%d\n",print->add);
        	fprintf(fp,"%d\n",print->add);
        	print=print->next;
	}
	printf("\n\n");
	
	//fflush(instructions_ip);	
	//fclose(instructions_ip);
	//printf("asdfgh\n");
	//instructions_ip=fopen("instructions_ip.txt","r+");
	rewind(instructions_ip);
	//puts(op);
	FILE *machine_code_op=fopen("../mach_code/machine_code_op.txt","w+");
	char c4,str[100],c5;
	//c4=fscanf(instructions_ip,"%s",str);
	//c4=fscanf(instructions_ip,"%s",str);
	do {
		//printf("line 374\n");
		c4=fscanf(instructions_ip," %s",str);
		if(c4==EOF)
			break;
		//printf("+2 lines\n");
		int len;
		for(len=0 ; str[len]!='\0' ; ++len) {
		//	printf("%c ",str[len]);
			continue;
		}
		//puts(str);
		//printf("\n");
		//puts("print hua");
		if(str[len-1]==':') {
		
			//printf("len\n");
			//fprintf(machine_code_op,"\n");
			//printf("machine code 1\n");
		}	
		else {
		
			//printf("non label\n");
			char s1[100],s2[100],c5,c6;
			//printf("line 396\n");
			//puts(str);
			Opcodes *currnode=get_Opcode_Node(str);
			printf("%s::%s::%s\n",currnode->name,currnode->code,currnode->format);
			//puts(currnode->format);
			//printf("node mili\n");
			char Op_code[100];
			//Op_code=(char*)malloc(sizeof(char)*100);
			strcpy(Op_code,currnode->code);
			//int p;
			//printf("\n");	
			//puts(Op_code);
			fprintf(machine_code_op,"%s",Op_code);
			//printf("machine code 2\n");	
			if(strcmp(currnode->format,"r")==0) {
				
				c5=fscanf(instructions_ip,"%s",s1);
				//printf("%s\n",s1);
				fprintf(machine_code_op,"%s\n",get_register_binary(s1));
				//printf("%s\n",s1);
				//printf("machine code 4\n");
			}
			else if(strcmp(currnode->format,"rr")==0) { 
			
				c5=fscanf(instructions_ip,"%s",s1);
				c6=fscanf(instructions_ip,"%s",s2);
				fprintf(machine_code_op,"%s",get_register_binary(s1));
				//printf("%s\n",s1);
				//printf("machine code 6\n");
				fprintf(machine_code_op,"%s\n",get_register_binary(s2));
				//printf("%s\n",s2);
				//printf("machine code 7\n");
				//printf("machine code 8\n");
			}
			else if(strcmp(currnode->format,"z")==0) {
				
				fprintf(machine_code_op,"\n");
				//printf("machine code 9\n");
			}
			else if(strcmp(currnode->format,"ri")==0) {
				
				//puts("reg imm");
				int var;
				c5=fscanf(instructions_ip,"%s",s1);
				//puts(s1);
				//printf("gaga\n");
				c6=fscanf(instructions_ip,"%d",&var);
				//printf("%d\n",var);
				fprintf(machine_code_op,"%s",get_register_binary(s1));
				int *conv;
				conv=get_binary_conv8(var);
				int j;
				for(j=0 ; j<8 ; j++) 
					fprintf(machine_code_op,"%d",conv[j]);
				fprintf(machine_code_op,"\n");
				//printf("machine code 10\n");	
			}
			else if(strcmp(currnode->format,"a")==0) {
				
				int var;
				c5=fscanf(instructions_ip,"%s",s1);
				int *conv;
				conv=get_add_from_symbol(s1);
				int j;
				for(j=0 ; j<10 ; j++)
					fprintf(machine_code_op,"%d",conv[j]);
				fprintf(machine_code_op,"\n");
			}
				 
		}
		//puts("while exe\n");

	} while(c4!=EOF);	
 
 	//printf("almost done\n");
}
