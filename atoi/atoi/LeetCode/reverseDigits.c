#include <stdio.h>
#include <math.h>

int reverse(int x) {
    if (x == 0)
        return x;
    
    long long rev = 0;
	int abs_x = 0;
    
    abs_x = abs(x);
    
    while (abs_x > 0){
        int rem = abs_x%10;
        
        rev = rev*10 + rem;
        abs_x /= 10;
    }

	if (rev > (pow (2, 31) -1))
			return 0;

    return (x < 0) ? (0-rev) : rev;
}

int main (){
	int x;

	printf ("Enter the value to be reversed:\n");
	scanf ("%d", &x);

	printf ("The reverse digits of the integer %d is %d\n", x, reverse(x));

	return 0;
}
