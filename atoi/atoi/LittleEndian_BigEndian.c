#include <stdio.h>

int main(){
	int i = 1;//0x00000001 is stored as 01 00 00 00 on my machine
	char *c = (char *)&i; //gets the address of i
	if (*c) //de-referencing the value at c (with i casted into char) gets the first byte of the memory address i.e. lowest memory address
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
}
