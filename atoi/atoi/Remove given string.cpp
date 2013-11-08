#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

string stringRemoval(string str1, string str2){
	int i, j;
	for (i = 0; i < str1.size(); i++){
		str2.erase (remove(str2.begin(), str2.end(), str1[i]), str2.end());
	}

	cout << str2 << endl;

	return str2;
}

int main(){
	string s1, s2;

	cin >> s1;
	cin >> s2;

	s2 = stringRemoval(s1, s2);

	cout << s2 << endl;
}
