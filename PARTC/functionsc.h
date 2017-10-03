#ifndef FC__
#define FC__

#include<stdio.h>
#include<string.h>

extern char buffer[],immediate[],reg_binary[],addr_binary[];
extern int pc;
extern int Register[];
extern int flag_reg[];
extern int MSFreg;
extern FILE *fp_mach;

void show_stats();
int conversion(char a[]);
unsigned short int ALU(const char* signal,unsigned short int a,unsigned short int b);
//-------------------------Arithmetic Functions----------------
void ADDI(int regI, int imm);
void ADD(int regI1, int regI2);

void SUBI(int regI, int imm);
void SUB(int regI1, int regI2);

void MULI(int regI, int imm);
void MUL(int regI1, int regI2);

void DIVI(int regI, int imm);
void DIV(int regI1, int regI2);

void AND(int regI1, int regI2);

void OR(int regI1, int regI2);

void LSHIFT(int regI);

void RSHIFT(int regI);

void NOT(int regI);

void CMPI(int regI, int imm);
void CMP(int regI1,int regI2 );
//--------------------------------------------------

//--------Data Transfer----------------------------
void MOVI(int regI, int imm);
void MOV(int regI1, int regI2);
//------------------------------------------------

//--------------DATA I/O--------------------------
void IN(int regI);
void OUT(int regI);
//------------------------------------------------

//---------Control Transfer-----------------------
void JMP(int address);
void JNQ(int address);
void JEQ(int address);
void JLT(int address);
void JGT(int address);

void RET();
void MSF();
void HLT();
//--------Machine Operations-------------------------
void energyMonitor();
void doorTimer();
void filterStatus();
void addWater();
void doorOpen();
void doorClose();
//-------------------------------------------------
#endif
