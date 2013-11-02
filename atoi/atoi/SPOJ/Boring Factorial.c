#include <stdio.h>

long int primeModulo (long long int n, long long int p){
	long long int ans0 = 1, ans1 = 1;
	long int i, m, res = 1;
	/*if (n >= p)
		return 0;
	else
	{
		for (i=1; i <= (n+1)/2; i++){
			ans0 *= (2*i+0)%p;
			ans1 *= (2*i+1)%p;
		}
	}*/
	while (n > 0) { 
		for (i = 1, m = n % p; i <= m; i++) 
			res = (res * i) % p; 
		if ((n /= p) % 2 > 0) 
			res = p - res; 
	} 
	return res; 
}

int main(){
	int t;
	long long int N, P, ans;

	scanf("%d", &t);

	while(t--){
		scanf("%lld, %lld", &N, &P);
		printf("%ld\n", primeModulo(N, P));
	}
	return 0;
}
