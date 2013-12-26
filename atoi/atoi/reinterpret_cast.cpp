// An example that uses reinterpret_cast.
#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int i;
	char *p = "This is a String.";
	//strcpy(p, "This is a String.");
	i = reinterpret_cast<int> (p); // cast pointer to integer
	cout << i;
	//delete [] p;
	return 0;
}
