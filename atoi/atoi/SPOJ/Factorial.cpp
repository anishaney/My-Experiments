#include<iostream>
#include<cstdio>
#define LL long long int

using namespace std;

LL n;
LL power(LL num)
{
	LL sum=0,m,temp;
	m=n;
	while(m>0)
	{
		temp=m/num;
		sum+=temp;
		m/=num;
	}
	return sum;
}
int main()
{
	int t;
	LL k1,k2,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		k1=power(2);
		k2=power(5);
         	ans=min(k1,k2);
		printf("%lld\n",ans);	
	}
	return 0;
}
