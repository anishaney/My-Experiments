#include <stdio.h>

int trailingZeroes(int n){
	int trailingZero = 0;

	if (n < 5)
		return 0;

	while (n > 0){
		trailingZero += n/5;
		n /= 5;
	}

	return trailingZero;
}
