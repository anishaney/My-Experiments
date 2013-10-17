#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getPath(int width, char* str, char* DVRstr){

	int i = 0, gridRow = 0, gridColumn = 0, destRow, destColumn, j = 0;
	//char *DVRstr = (char *) maclloc (sizeof(char));
	
	while (i < strlen(str)){
		destRow = ((int)str[i] - (int)'a') / width;
		destColumn = ((int)str[i] - (int)'a') % width;

		while (gridRow < destRow){
			DVRstr[j] = 'd';
			gridRow++;
			j++;
		}

		while (gridRow > destRow){
			DVRstr[j] = 'u';
			gridRow--;
			j++;
		}

		while (gridColumn < destColumn){
			DVRstr[j] = 'r';
			gridColumn++;
			j++;
		}

		while (gridColumn > destColumn){
			DVRstr[j] = 'l';
			gridColumn--;
			j++;
		}

		DVRstr[j++] = '!';
		i++;
	}
	DVRstr[j] = '\0';

	return DVRstr;
}

int main(){

	int width = 5;
	char str[10] = "up", DVRstr[50];

	getPath(width, str, DVRstr);

	printf("The return string is %s\n", DVRstr);

	return 0;
}
