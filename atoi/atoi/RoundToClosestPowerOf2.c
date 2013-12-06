#include <stdio.h>

int closestPower2(int num){
	int temp;

	if (!(num & (num-1))){
		return num;
	}
	do{
		num++;
		temp = num - 1;
	}while (num & temp);

	return num;
}

int main(){
	int num, Closest_power2;

	scanf("%d", &num);
	Closest_power2 = closestPower2(num);

	printf("%d\n", Closest_power2);
}
