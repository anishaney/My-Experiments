#include <stdio.h>
#include <math.h>

unsigned long long int smallFactorial(int n){
	if (n < 1)
		return 1;
	else
		return n*smallFactorial(n-1);
}

int main(){
	int t, n;
	
	scanf("%d\n", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", smallFactorial(n));
	}
	return 0;
}
