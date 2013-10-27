#include <stdio.h>
#include <math.h>

int main(){
	long double pi = 0.0;
	double atan1, atan3;

	atan1 = atan2(1.0, 5.0);
	atan3 = atan2(1.0, 239.0);

	printf("%lf\n", atan1);
	printf("%lf\n", atan3);

	pi = (long double)(16*atan1) - (4*atan3);
	
	printf("Value of pi = %Lf\n", pi);

	return 0;
}
