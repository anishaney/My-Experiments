/* Algorithm: Reverse the whole string first. Then reverse each word in the reversed string.
 * Example: 
 * Given String: This is my Test.
 * First Reversal: .tesT ym si sihT
 * Second Reversal: Test. my is This
*/

/* Complexity: O(n+n) i.e. O(n)
*/

#include <stdio.h>
#include <string.h>

char * reverseString(char str[]){
	char str_rev[20];

	//strcpy(str_rev, str);
	char temp;
	int i = 0, j = strlen(str)-1, k;
	while (i < j){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	printf("%s\n", str);

	j = -1;
	i = 0;

	while (j != strlen(str)){
		j++;
		if (str[j] == '\0' || str[j] == ' '){
			k = j - 1;
			while (i < k){
				temp = str[i];
				str[i] = str[k];
				str[k] = temp;
				i++;
				k--;
			}
			i = j+1;
			printf("%d %c\n", i, str[i]);
		}
	}
	return str;
}

int main(){
	char str[20] = "This is my Test.";
	printf("%s\n", str);
	reverseString(str);
	printf("%s\n", str);
	return 0;
}
