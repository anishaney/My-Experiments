/*segmented sieve*/
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIMIT 1000000000  /*10^9*/
#define NEW_MAX  31623 /*SQUARE ROOT OF 1000000000*/
#define MAX_WIDTH 100000   /*10^5*/
int flags[NEW_MAX+1];  /*TO PREVENT SEGMENTATION FAULT goblal so initialised to 0,true*/    

void initialise(int flagarr[],long int n) 
/*initialise all elements to true from 1 to n*/
{
    long int i;
    for(i=3;i<=n;i+=2)
        flagarr[i]=0;
}

void sieve(unsigned long m,unsigned long n,int seg_flags[])
{

    unsigned long p,i,limit;  

    /*Seperate inner loop for p=2 so that evens are not iterated*/
    if(m%2==0)
        i=m;
    else
        i=m+1;
    /*i is now next even > m*/
    for(;i<=n;i+=2)
    {

        seg_flags[i-m+1]=1;

    }
    if(seg_flags==flags)
        limit=NEW_MAX;
    else
        limit=sqrt(n);
    for(p=3;p<=limit+1;p+=2)  /*initial p+=2 bcoz we need not check even*/
    {
        if(flags[p]==0)
        {


            for(i=p*p; i<=n ;i+=p)  
            /*start from p square since under it would have been cut*/
            {
                if(i<m)
                    continue;
                seg_flags[i-m+1]=1; 
                     /*p*p,  p*p+p,  p*p + 2p   are not primes*/

            }
        }
    }
}

void print_sieve(unsigned long m,unsigned long n,int flagarr[])
{
    unsigned long i;
    if(m<3)
    {printf("2\n");m=3;}
    if(m%2==0)
        i=m+1;
    else
        i=m;
if(flags==flagarr)    /*print non-segented sieve*/  
{
    for(;i<=n;i+=2)
        if(flagarr[i]==0)
                printf("%lu\n",i);
}
else {
 //print segmented

    for(;i<=n;i+=2)
        if(flagarr[i-m+1]==0)
                printf("%lu\n",i);
}}

int main()
{
    unsigned long m,n;
    int t;
    int seg_flags[MAX_WIDTH+100];
    /*setting of flags for prime nos. by sieve of erasthromas upto NEW_MAX*/
    sieve(1,NEW_MAX,flags);
    /*end of initial sieving*/
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lu %lu",&m,&n);
        if(n<=NEW_MAX)
            print_sieve(m,n,flags); 
            /*NO SEGMENTED SIEVING NECESSARY*/
        else if(m>NEW_MAX)
        {
            initialise(seg_flags,n-m+1);  
            /*segmented sieving necessary*/
            sieve(m,n,seg_flags);
            print_sieve(m,n,seg_flags);
        }
        else if(m<=NEW_MAX && n>NEW_MAX) 
         /*PARTIAL SEGMENTED SIEVING NECESSARY*/
        {
            print_sieve(m,NEW_MAX,flags);
            /*now lower bound for seg sieving is new_max+1*/
            initialise(seg_flags,n-NEW_MAX);
            sieve(NEW_MAX+1,n,seg_flags);
            print_sieve(NEW_MAX+1,n,seg_flags);
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}
