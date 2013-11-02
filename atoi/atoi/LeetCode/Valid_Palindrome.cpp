#include <iostream>
#include <string.h>

using namespace std;

/*bool*/
void isPalindrome(string s){
	int i, j;

	int length = s.length();

	char ci, cj;

	for (i=0, j=length-1; i<length && j>=0; i++, j--){
		while (ci = toupper(s[i]), (ci < 'A' && ci > '9' || ci > 'Z' || ci < '0') && i < length-1){
			cout << ci;
			i++;
		}
		while (cj = toupper(s[j]), (cj < 'A' || cj > 'Z' || cj < '0' || cj > '9') && j >= 0){
			cout << cj;
			j--;
		}
		cout << endl;
	}

	cout << i << '\t' << j << endl;
}

int main(){
	string str = "Race a '90 car.";

	isPalindrome(str);

	return 0;
}
