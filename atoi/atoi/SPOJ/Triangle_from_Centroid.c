#include <stdio.h>
#include <math.h>

typedef long double LD;

float area(LD xa, LD xb, LD xc, LD a){
	LD b, c;
	float ar = 0.0;
	LD s, u, v, w;
	
	u = 3*xa; v = 3*xb; w = 3*xc;
	s = (u+v+w)/2;

	/*if (xa == xb && xb == xc)
		ar = (float)((sqrt(3)/4)*a*a);
	else*/
		ar = (sqrt((2*((u*u*v*v)+(v*v*w*w)+(w*w*u*u)))-((u*u*u*u)+(v*v*v*v)+(w*w*w*w))))/3;
	
	return ar;
}

float distance(LD xa, LD xb, LD xc, LD a){
	LD b, c, dist = 0.0;
	LD s, u, v, w;
	
	u = 3*xa; v = 3*xb; w = 3*xc;
	s = (u+v+w)/2;

	if (xa == xb && xb == xc)
		return dist;
}

int main(){
	int t;
	LD xa, xb, xc, a;

	scanf("%d", &t);

	while (t--){
		scanf("%Lf %Lf %Lf %Lf", &a, &xa, &xb, &xc);
		printf("%.3f", area(xa, xb, xc, a));
		printf(" %.3f\n", distance(xa, xb, xc, a));
	}
}
