#include <stdio.h>

int noOfOnesInteger (long int n){
	int count = 0;

	while(n){
		count++;
		n &= (n-1);
	}

	return count;
}

int main(){
	long int n;
	int no_of_ones;
	scanf ("%ld", &n);
	
	no_of_ones = noOfOnesInteger (n);

	printf("%d\n", no_of_ones);
}
