#include <iostream.h>
#include <conio.h>
#include <string.h>

/*int atoi(char *name)
{
	int ascii=48; // ascii code for zero
	int len = strlen(name)-1;
	int index;
	int intVal=0;
	int tens=1;
	for(index=len;index>=0; index--)
	{
		intVal = intVal*10+((int)(name[index]-ascii));
		//tens= tens*10;
	}
	return intVal;
	
}*/

int main(){
	char s[20] = "A";
	int i;
	//integer = atoi(s);

	int count = 0; 
	for(i=0; i < 10; i++) 
		count = ++count; 

	printf("%d", count);
	getch();
	return 0;
}