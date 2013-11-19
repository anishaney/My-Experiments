#include <stdio.h>

int removeDuplicates(int A[], int n){
	int i = 0, j, k, sum = 0, l, z = n, count;

	/*for (i = 0; i < n; i++){
		sum = A[i];
		j = i+1;
		sum += A[j];
		while (sum == (j-i)*A[i]){
			sum += A[j];
			j++;
		}
		l = j;
		for (k = i+1; k < z-(--j-i); k++){
			A[k] = A[l++];
		}
		z = z-(--j-i);
	}*/

	while(A[i] != A[n-1]){
		j = i+1;
		while (A[i] == A[j]){
			j++;
			continue;
		}
		for (k = i+1; k < j; k++){
			A[k] = A[j];
		}
		i++;
	}
	i = 0;
	count = 0;
	while(A[i] != A[n-1]){
		i++;
		count++;
	}
	return count+1;
}

int main(){
	int A[13] = {1,1,2,2,2,3,4,4,5,6,6,6,6};
	int n = sizeof(A)/sizeof(A[0]);

	printf("%d\n", removeDuplicates(A, n));
	return 0;
}
