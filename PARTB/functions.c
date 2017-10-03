#include"functions.h"

Opcodes* map[13] = {NULL};
Symbol_table *head = NULL;

int get_map_index(char Name[]) {	

	int val=0,i;
	for(i=0 ; Name[i]!='\0' ; i++) {
		
		val+=Name[i];
	}
	return val%11;
}

// Inserts the node 'Node' in the hash map at position idx

void Insert_at_index(int idx, Opcodes*Node) {

	if(map[idx]==NULL) {
		
		map[idx]=Node;
		Node->next=NULL;
		return ;
	}
	
	Opcodes *temp=map[idx];
	while(temp->next!=NULL) {
	
		temp=temp->next;
	}
	temp->next=Node;
	Node->next=NULL;
}

// Finds index of Operation in the hash map and calss Insert_at_index()

void Insert_into_map(Opcodes *Node) {
	
	int idx=get_map_index(Node->name);
	Insert_at_index(idx,Node);	
}

// returns Node corresponding to Operation name 'op_code' by searching in hash map

Opcodes* get_Opcode_Node(char *op_name) {

	//puts(op_code);
	Opcodes*temp = NULL;
	int idx=get_map_index(op_name);
	//printf("%d index\n",idx);
	if(map[idx]==NULL) {
		
		//printf("Invalid Opcode\n");
        	return temp;
	}
	//printf("type\n");
	temp=map[idx];
	while(strcmp(temp->name,op_name)!=0) {
		//puts(temp->name);
		temp=temp->next;	
		if(temp==NULL)
			break;
	}
	//printf("%s %s %s\n",temp->name,temp->code,temp->format);
	//printf("value not returned\n");
	if(temp==NULL)
        {
            printf("Opcode not found!\n");
            return NULL;
        }
        else
        {
            return temp;
        }
}

// returns 8 bit binary conversion of a number

int* get_binary_conv8(int var) {

	int *ans,i;
	ans=(int*)malloc(8*sizeof(int));
	for(i=0 ; i<8 ; i++) {
		
		ans[i]=0;
	}
	i=i-1;
	int val=var,x,y;
	while(var!=0) {
	
		x=var%2;
		y=var/2;
        	ans[i--]=x;
         	var=y;
    	}
    	return 	ans;
}

// returns 10 bit binary conversion of a number

int* get_binary_conv10(int var) {

	int *ans,i;
	ans=(int*)malloc(sizeof(int)*10);
	for(i=0 ; i<10 ; i++) {
		
		ans[i]=0;
	}
	i=i-1;
	int val=var,x,y;
	while(var!=0) {
	
		x=var%2;
		y=var/2;
        	ans[i--]=x;
         	var=y;
    	}
    	return ans;
}

// returns 10 bit binary address of label from symbol table

int* get_add_from_symbol(char *label_name) {

	Symbol_table *tmp=head;
	if(tmp==NULL) {
		
		printf("No label found\n");
		return NULL;
	}
	while(strcmp(tmp->name,label_name)) {
		tmp=tmp->next;
		if(tmp==NULL)
			break;	
	}
	if(tmp==NULL){
		printf("Label %s not made\n",label_name);	
	}
	int *converted_add=get_binary_conv10(tmp->add);
	return converted_add;
} 

// returns the binary equivalent of register name

char* get_register_binary(char *reg) {

	char *val;
	if(!strcmp(reg,"R00")) {
		val="00000";
		return val;
	}
	if(!strcmp(reg,"R01")) {
		val="00001";
		return val;
	}
	if(!strcmp(reg,"R02")) {
		val="00010";
		return val;
	}
	if(!strcmp(reg,"R03")) {
		val="00011";
		return val;
	}
	if(!strcmp(reg,"R04")) {
		val="00100";
		return val;
	}
	if(!strcmp(reg,"R05")) {
		val="00101";
		return val;
	}
	if(!strcmp(reg,"R06")) {
		val="00110";
		return val;
	}
	if(!strcmp(reg,"R07")) {
		val="00111";
		return val;
	}
	if(!strcmp(reg,"R08")) {
		val="01000";
		return val;
	}
	if(!strcmp(reg,"R09")) {
		val="01001";
		return val;
	}
	if(!strcmp(reg,"R10")) {
		val="01010";
		return val;
	}
	if(!strcmp(reg,"R11")) {
		val="01011";
		return val;
	}
	if(!strcmp(reg,"R12")) {
		val="01100";
		return val;
	}
	if(!strcmp(reg,"R13")) {
		val="01101";
		return val;
	}
	if(!strcmp(reg,"R14")) {
		val="01110";
		return val;
	}
	if(!strcmp(reg,"R15")) {
		val="01111";
		return val;
	}
	if(!strcmp(reg,"R16")) {
		val="10000";
		return val;
	}
	if(!strcmp(reg,"R17")) {
		val="10001";
		return val;
	}
	if(!strcmp(reg,"R18")) {
		val="10010";
		return val;
	}
	if(!strcmp(reg,"R19")) {
		val="10011";
		return val;
	}
	if(!strcmp(reg,"R20")) {
		val="10100";
		return val;
	}
	if(!strcmp(reg,"R21")) {
		val="10101";
		return val;
	}
	if(!strcmp(reg,"R22")) {
		val="10110";
		return val;
	}
	if(!strcmp(reg,"R23")) {
		val="10111";
		return val;
	}
	if(!strcmp(reg,"R24")) {
		val="11000";
		return val;
	}
	if(!strcmp(reg,"R25")) {
		val="11001";
		return val;
	}
	if(!strcmp(reg,"R26")) {
		val="11010";
		return val;
	}
	if(!strcmp(reg,"R27")) {
		val="11011";
		return val;
	}
	if(!strcmp(reg,"R28")) {
		val="11100";
		return val;
	}
	if(!strcmp(reg,"R29")) {
		val="11101";
		return val;
	}
	if(!strcmp(reg,"R30")) {
		val="11110";
		return val;
	}
	if(!strcmp(reg,"R31")) {
		val="11111";
		return val;
	}
}


