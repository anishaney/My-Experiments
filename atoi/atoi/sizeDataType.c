#include <stdio.h>

int main(){
	char ch;
	int it;
	long int lit;
	float ft;
	double dft;
	long double ldft;

	printf("%c, %d, %ld, %f, %lf, %Lf\n", (char)sizeof(ch), sizeof(it), (long int)sizeof(lit), (float)sizeof(ft), (double)sizeof(dft), (long double)sizeof(ldft));
}
