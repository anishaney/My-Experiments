int isPalindrome (int x){
	int temp = x;
    
    long long reverse = 0;
    
    while (temp > 0){
        reverse = reverse*10 + temp%10;
        temp /= 10;
    }

	printf ("%lld, %d\n", reverse, x);
    
    return (reverse == (long long)x) ? 1 : 0;
}
