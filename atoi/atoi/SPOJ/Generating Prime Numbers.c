#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned long long int LLI;

void printPrimeNos(int t, LLI m[], LLI n[]){
	int i;
	LLI k, j, p;
	int isPrime[100000];
	int isPrime2[100000];

	for (i = 0; i < t; i++){
		if (n[i] - m[i] > 100000){
			printf("Too much difference between inputs.\n");
			continue;
		}
		if (m[i] > n[i]){
			printf("Inputs are not as expected.\n");
			continue;
		}
		if (m[i] > 1000000000 || n[i] > 1000000000){
			printf("Too long inputs.\n");
			continue;
		}

		if (m[i] == 1 && n[i] != 1)
			isPrime[m[i]] = true;

		if (m[i] < 31623 && n

		for (k = 2; k <= sqrt(n[i]); k++){
			if (!isPrime[k]){
				j = pow(k, 2);
				p = 1;
				while(j <= n[i]){
					isPrime[j] = true;
					j = pow(k, 2) + p*k;
					p++;
				}
			}
		}

		for (k = 2; k <= sqrt(n[i]); k++){
			if (!isPrime[k]){
				j = pow(k, 2);
				p = 1;
				while(j <= n[i]){
					isPrime[j] = true;
					j = pow(k, 2) + p*k;
					p++;
				}
			}
		}

		for (k = m[i]; k <= n[i]; k++){
			if (!isPrime[k])
				printf("%lld\n", k);
		}
		printf("\n");
	}
}


/*Can increment the value by 2 if m[i] is even. Initialize a variable to m[i] if it is odd or m[i]+1 if it is even. CHECK if m[i] = 1 OR 2*/

/*	for (i = 0; i <= t; i++){
		if (n[i] - m[i] > 100000){
			printf("Too much difference between inputs.\n");
			continue;
		}
		if (m[i] > n[i]){
			printf("Inputs are not as expected.\n");
			continue;
		}
		if (m[i] > 1000000000 || n[i] > 1000000000){
			printf("Too long inputs.\n");
			continue;
		}
		for(j = m[i]; j <= n[i]; j++){
			p = j;
			isPrime = 1;

			if (p == 1)
				continue;

			for (k = 2; k < p; k++){
				if (!(p % k)){
					isPrime = 0;
					break;
				}
				else
					continue;
			}
			if (isPrime)
				printf("%ld\n", p);
		}
		printf("\n");
	}*/

int main(){
	int t, i;
	LLI m[10], n[10];
	
	printf("Enter no. of Test Cases:\n");

	scanf("%d", &t);

	for (i = 0; i < t; i++){
		 scanf("%lld %lld", &m[i], &n[i]);
	}

	printPrimeNos(t, m, n);

	return 0;
}
