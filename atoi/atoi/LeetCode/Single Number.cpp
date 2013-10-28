#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {

	int XOR = 0;
	for (int i = 0; i < n; i++){
		XOR = XOR^A[i];
	}
	return XOR;
}

int main(){
	int n, A[6] = {1, 1, 2, 3, 3, 2};

	n = sizeof(A)/sizeof(A[0]);

	cout << n << endl;

	int XOR;

	XOR = singleNumber(A, n);

	cout << XOR << endl;
}
