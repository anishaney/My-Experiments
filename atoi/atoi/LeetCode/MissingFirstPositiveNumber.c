#include <stdio.h>

int firstMissingPositive (int A[], int n){
	int i = 0, temp;

	while (i < n){
		if (A[i] < 1 || A[i] > n-1 || A[i] == i){
			i++;
		}
		else{
			temp = A[i];
			A[i] = A[A[i]];
			A[temp] = temp;
		}
	}

	for (i = 1; i < n; i++){
		if (A[i] != i)
			return i;
	}
	return n;
}

int main(){
	int i, missingPositive;
	
	int A[11] = {8,-1,2,0,-3,1,-6,5,9,-2,4};

	int n = sizeof(A)/sizeof(A[0]);

	printf("%d\n", n);

	for (i = 0; i < n-1; i++)
		printf("%d\t", A[i]);
	printf("\n");

	missingPositive = firstMissingPositive(A, n);

	printf("%d\n", missingPositive);

	for (i = 0; i < n-1; i++)
		printf("%d\t", A[i]);
	printf("\n");
}
