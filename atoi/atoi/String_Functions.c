#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*remove_spaces(char str1){
	char *ptr = str1;
	
	while(*ptr != '\0'){
		if (*ptr == ' '){
			
}*/
char * longest_word(char *s1, char *str){
	char *ptr = str, *ptr1 = str;
	int max_count = 0, count = 0, i;
	
	/*int j = 0, k = 0;

	strcpy(str2, str);

	int str_length = strlen(str);
	printf("The length of the string is %d\n", str_length);*/

//Using pointers

	while(*ptr != '\0'){
		while (*ptr != ' ' && *ptr != '\0'){
			ptr++;
			count++;
		}
		if (max_count < count){
			i = 0;
			max_count = count;
			while (ptr != ptr1){
				s1[i] = *ptr1;
				ptr1++;
				i++;
			}
			s1[i] = '\0';
		}
		ptr++;
		ptr1 = ptr;
		count = 0;
	}

//Using string (array of characters)

	/*while(j < str_length){
		while (str[j] != ' ' && str[j] != '\0'){
			printf("%c\t", str[j]);
			j++;
			count++;
			printf("%d\n", count);
		}
		if (max_count < count){
			i = 0;
			max_count = count;
			//printf("Max_count = %d\n", max_count);
			while (str[j] != str2[k]){
				s1[i] = str2[k];
				k++;
				i++;
			}
			s1[i] = '\0';
			//printf("The longest word is %s\n", s1);
		}
		printf("\tj = %d\n", j);
		j++;
		k = j;
		count = 0;
	}*/
	
	return s1;
}

int no_of_letter_e(char* str){
	char *ptr = str;
	int count = 0;

	while (*ptr != '\0'){
		if (*ptr == 'e'){
			count ++;
		}
		ptr++;
	}
	return count;
}

int no_of_integers(char* str){
	char *ptr = str;
	int count = 0;

	while (*ptr != '\0'){
		if ((int)*ptr > 48 && (int)*ptr < 58)
			count++;
		ptr++;
	}
	return count;	
}


int no_of_words(char* str){
	char *ptr = str;
	int count = 0;

	while (*ptr != '\0'){
		while (*ptr != ' ' && *ptr != '\0' && *ptr != '.' && *ptr != ','){
			ptr++;
		}
		count++;
		ptr++;
	}
	return count;
}


int no_of_sentences(char* str){
	char *ptr = str;
	int count = 0;

	while (*ptr != '\0'){
		ptr++;
		if (*ptr == '.' || *ptr == '\0')
			count++;
		if (*ptr == '.' && *(++ptr) == '\0')
			count--;
	}
	return count;	
}
no_of_doubles(char str){
}

int main(){
	char str[90] = "my brother is taller than me@1233334. I always a short man,but smart than him.";
	char str1[90];
	int no_of_e = 0, total_words = 0, total_integers = 0, total_sentences = 0;

	char s1[20];

	strcpy(str1, str);

	longest_word(s1, str);
	printf("The longest word is %s\n", s1);

	no_of_e = no_of_letter_e(str);
	printf("No. of times letter 'e' occurs in the sentence is %d\n", no_of_e);

	total_words = no_of_words(str);
	printf("No. of words in the sentence is %d\n", total_words);

	total_integers = no_of_integers(str);
	printf("No. of integers in the sentence is %d\n", total_integers);

	total_sentences = no_of_sentences(str);
	printf("Total no. of sentences in the string are %d\n", total_sentences);

	/*remove_spaces(str1);
	no_of_doubles(str);*/

	getchar();
	return 0;
}
