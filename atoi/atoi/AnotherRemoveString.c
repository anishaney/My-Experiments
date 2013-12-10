#include <stdio.h>
#include <stdlib.h>

#define NO_OF_CHARS 256

int *getCharCountArray(char *str){
	int i;
	int *count = (int*)calloc (sizeof(int), NO_OF_CHARS);
	for (i = 0; i < *(str+i); i++){
		printf("%c %d\t", *(str+i), count[*(str+i)]++);
	}
	return count;
}

char *removeString(char* str, char* mask_str){
	int *count = getCharCountArray(mask_str);
	int ip_ind = 0, res_ind = 0;
	char temp;
	
	while(*(str + ip_ind)){
		temp = *(str + ip_ind);
		if (count[temp] == 0){
			*(str+res_ind) = *(str+ip_ind);
			res_ind++;
		}
		ip_ind++;
	}
	*(str+res_ind) = '\0';

	return str;
}

int main(){
	char mask_str[] = "hello";
	char str[] = "leetCode";

	printf("\n%s\n", removeString(str, mask_str));

	return 0;
}
