#include <iostream>

using namespace std;

int main(){
	int i = 5;
	int const *int_ptr;
	int_ptr = &i;
	cout << int_ptr << endl;
	int_ptr++;
	i = 10;
	cout << i << '\n' << int_ptr << endl;
	i++;
	//cout << i;
	return 0;
}
