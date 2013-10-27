#include <stdio.h>

void getFirstPalindrome (int t, unsigned long long int m[]){
	int i, rem, j, k;
	unsigned long long int num, n, reverse;

	printf("Output:\n");

	for (i = 0; i < t; i++){
		num = m[i];
		while (reverse != num){
			n = num;
			reverse = 0;
			while (n != 0){
				reverse = reverse * 10;
				reverse = reverse + n%10;
				n = n/10;
			}
			if (num == reverse)
				break;
			num++;
		}
		printf("%lld\n", reverse);
	}
}

int main(){
	int t, i;
	unsigned long long int m[10];

	printf("Input:\n");

	scanf("%d", &t);

	for (i = 0; i < t; i++)
		scanf("%lld", &m[i]);

	getFirstPalindrome(t, m);

	return 0;
}
