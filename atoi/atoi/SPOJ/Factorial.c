#include <stdio.h>

typedef long long int LLI;

LLI n;

LLI power (LLI num){
	LLI sum = 0, j, temp;

	j = n;
	while (j > 0){
		temp = j/num;
		sum += temp;
		j = j/num;
	}
	return sum;
}

/*void getFactorial (int t, LLI m[]){
	int i, j, k;
	LLI num, count, product;

	printf("Output:\n");

	j = t;

	while (t){
		product = 1;
		count = m[j - t];
		while (count > 0){
			product *= count--;
		}
		printf("%lld\n", product);
		t--;
	}
}*/

/*int main(){
	int t, i;
	LLI m[10];

	printf("Input:\n");

	scanf("%d", &t);

	for (i = 0; i < t; i++)
		scanf("%lld", &m[i]);

	getFactorial(t, m);

	return 0;
}*/

int main()
{
	int t;
	LLI k1,k2,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		k1=power(2);
		k2=power(5);
         	if (k1 < k2)
			ans = k1;
		else
			ans = k2;

		printf("%lld\n", ans);	
	}
	return 0;
}
