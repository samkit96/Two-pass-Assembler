#include"functionsc.h"
#include <stdlib.h>

int main(int argc,char* argv[])
{
	int i,j;
		
	reg_binary[5] = '\0';
	immediate[8] = '\0';
	addr_binary[10] = '\0';
	char mnemonics[33][6]={
			"ADDI","SUBI","MULI","DIVI","CMPI","MOVI",
			"ADD","SUB","MUL","DIV","AND","OR","CMP","MOV",
			"JNQ","JEQ","JLT","JGT","JMP",
			"IN","OUT","NOT","LSHIFT","RSHIFT",
			"RET","MSF","HLT","DRPN","DRTM","ENGY","FLST","ADW","DRCL"
			};
	char bin_equi[33][17]={
			"000","001","010","011","100","101",
			"110000","110001","110010","110011","110100","110101","110110","110111",
			"111000","111001","111010","111011","111100",
			"11110100000","11110100001","11110100010","11110100011","11110100100",
			"1111010010100000","1111010010100001","1111010010100010","1111010010100011","1111010010100100","1111010010100101","1111010010100110","1111010010100111","1111010010101000"
			};


	fp_mach = fopen("../mach_code/machine_code_op.txt","r");
	fscanf(fp_mach,"%s",buffer);
	while(!feof(fp_mach)){
		if(buffer[0] == '0' || buffer[1] == '0'){			// ri
			for(i=0,j=3; i<5; i++,j++){				// Extracting the Register index
				reg_binary[i] = buffer[j];
			}
			for(i=0,j=8; i<8; i++,j++){				// Extracting the immediate value
				immediate[i] = buffer[j];
			}
			int imm_value = conversion(immediate);			// Converting to decimal
			int reg_index = conversion(reg_binary);		// Converting to decimal

//-------CALLING Corresponding FUNCTIONS---------
			if(!strncmp(bin_equi[0],buffer,3)){
				ADDI(reg_index,imm_value);j=0;
			}
			else if(!strncmp(bin_equi[1],buffer,3)){
				SUBI(reg_index,imm_value);j=1;
			}
			else if(!strncmp(bin_equi[2],buffer,3)){
				MULI(reg_index,imm_value);j=2;
			}
			else if(!strncmp(bin_equi[3],buffer,3)){
				DIVI(reg_index,imm_value);j=3;
			}
			else if(!strncmp(bin_equi[4],buffer,3)){
				CMPI(reg_index,imm_value);j=4;
			}
			else {
				MOVI(reg_index,imm_value);j=5;
			}
//-------------------------------------------
			pc += 1;
			printf("IR : %s R%d %d\n",mnemonics[j],reg_index,imm_value);
			printf("Status of Program Counter(PC) %d",pc);
			show_stats();
		}
		else if(buffer[0] == '1' && buffer[1] == '1' && buffer[2] == '0'){	// rr
			for(i=0,j=6; i<5; i++,j++){				// Extracting the Register index
				reg_binary[i] = buffer[j];
			}
			int reg_index1 = conversion(reg_binary);
			
			for(i=0,j=11; i<5; i++,j++){				// Extracting the Register index
				reg_binary[i] = buffer[j];
			}
			int reg_index2 = conversion(reg_binary);

//			"ADD","SUB","MUL","DIV","AND","OR","CMP","MOV",


//-------CALLING Corresponding FUNCTIONS---------
			if(!strncmp(bin_equi[6],buffer,6)){
				ADD(reg_index1,reg_index2);j=6;
			}
			else if(!strncmp(bin_equi[7],buffer,6)){
				SUB(reg_index1,reg_index2);j=7;
			}
			else if(!strncmp(bin_equi[8],buffer,6)){
				MUL(reg_index1,reg_index2);j=8;
			}
			else if(!strncmp(bin_equi[9],buffer,6)){
				DIV(reg_index1,reg_index2);j=9;
			}
			else if(!strncmp(bin_equi[10],buffer,6)){
				AND(reg_index1,reg_index2);j=10;
			}
			else if(!strncmp(bin_equi[11],buffer,6)){
				OR(reg_index1,reg_index2);j=11;
			}
			else if(!strncmp(bin_equi[12],buffer,6)){
				CMP(reg_index1,reg_index2);j=12;
			}
			else {
				MOV(reg_index1,reg_index2);j=13;
			}
//-------------------------------------------------
			pc += 1;
			printf("IR : %s R%d R%d\n",mnemonics[j],reg_index1,reg_index2);
			printf("Status of Program Counter(PC) %d",pc);
			show_stats();
		}
		else if(buffer[3] == '0' || buffer[4] == '1' || buffer[5] == '0'){	// a
			for(i=0,j=6; i<10; i++,j++){					// Get address
				addr_binary[i]	= buffer[j];	
			}

//			"JNQ","JEQ","JLT","JGT","JMP",

//-------CALLING Corresponding FUNCTIONS---------
			int address = conversion(addr_binary);
			if(!strncmp(bin_equi[14],buffer,6)){
				JNQ(address);j=14;
			}
			else if(!strncmp(bin_equi[15],buffer,6)){
				JEQ(address);j=15;
			}
			else if(!strncmp(bin_equi[16],buffer,6)){
				JLT(address);j=16;
			}
			else if(!strncmp(bin_equi[17],buffer,6)){
				JGT(address);j=17;
			}
			else {
				JMP(address);j=18;
			}
			printf("IR : %s %d\n",mnemonics[j],address);
			printf("Status of Program Counter(PC) %d",pc);
			show_stats();		

//----------------------------------------------			
		}
		else if(buffer[8] == '0' || buffer[9] == '1' || buffer[10] == '0'){	// r
			for(i=0,j=11; i<5; i++,j++){					// Get Register binary
				reg_binary[i] = buffer[j];
			}
			int reg_index = conversion(reg_binary);
//			"IN","OUT","NOT","LSHIFT","RSHIFT",

			if(!strncmp(bin_equi[19],buffer,11)){
				IN(reg_index);j=19;
			}
			else if(!strncmp(bin_equi[20],buffer,11)){
				OUT(reg_index);j=20;
			}
			else if(!strncmp(bin_equi[21],buffer,11)){
				NOT(reg_index);j=21;
			}
			else if(!strncmp(bin_equi[22],buffer,11)){
				LSHIFT(reg_index);j=22;
			}
			else {
				RSHIFT(reg_index);j=23;
			}
			pc+=1;
			printf("IR : %s R%d\n",mnemonics[j],reg_index);
			printf("Status of Program Counter(PC) %d",pc);
			show_stats();		

		}
		else{									// z
//			"RET","MSF","HLT","DRPN","DRTM","ENGY","FLST","ADW","DRCL"
			pc+=1;
			if(!strncmp(bin_equi[24],buffer,16)){
				RET();j=24;
			}
			else if(!strncmp(bin_equi[25],buffer,16)){
				MSF();j=25;
			}
			else if(!strncmp(bin_equi[26],buffer,16)){
				HLT();j=26;
			}
			else if(!strncmp(bin_equi[27],buffer,16)){
				doorOpen();j=27;
			}
			else if(!strncmp(bin_equi[28],buffer,16)){
				doorTimer();j=28;
			}
			else if(!strncmp(bin_equi[29],buffer,16)){
				energyMonitor();j=29;
			}
			else if(!strncmp(bin_equi[30],buffer,16)){
				filterStatus();j=30;
			}
			else if(!strncmp(bin_equi[31],buffer,16)){
				addWater();j=31;
			}
			else if(!strncmp(bin_equi[32],buffer,16)){
				doorClose();j=32;
			}
			printf("IR : %s\n",mnemonics[j]);
			printf("Status of Program Counter(PC) %d",pc);
			show_stats();		

		}
	fscanf(fp_mach,"%s",buffer);
	}
fclose(fp_mach);
return 0;
}

//------------------------------------------------
// IF a[0] == 0 || a[1] == 0 ri
// IF a[0] == 1 && a[1] == 1 && a[2] == 0 rr
// IF a[3] == 0 || a[4] == 1 || a[5] == 0 a
// IF a[3] == 1 && a[4] == 0 && a[5] == 1 r 
// IF a[8] == 0 || a[9] == 1 || a[10] ==  0 
/*
			"R00","R01","R02","R03","R04","R05","R06","R07","R08","R09","R10",
			"R11","R12","R13","R14","R15","R016","R017","R018","R019","R20",
			"R21","R22","R23","R24","R25","R26","R27","R28","R29","R30","R31",

			"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010",
			"01011","01100","01101","01110","01111","10000","10001","10010","10011","10100",
			"10101","10110","10111","11000","11001","11010","11011","11100","11101","11110","11111",
*/
