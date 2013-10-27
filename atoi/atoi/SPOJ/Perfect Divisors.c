#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void perfectDivisor(int n){
	long int sum = 1, sqrt_n, i;

	sqrt_n = sqrt(n);

	if (n == 1)
		sum = 0;

	for (i = 2; i <= sqrt_n; i++){
		if (n % i == 0)
			if (i != n/i)
				sum = sum + i + n/i;
			else
				sum = sum + i;
	}
	printf("%ld\n", sum);
}

int main(){
	long int t, n;

	scanf ("%ld", &t);

	while (t--){
		scanf("%ld", &n);

		perfectDivisor(n);
	}
	return 0;
}
