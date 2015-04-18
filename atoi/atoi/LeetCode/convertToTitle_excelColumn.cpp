#include <iostream>
#include <string>

using namespace std;

string convertToTitle (int n){
	string col = "", exl_col = "";
	int alpha;

	while (n){
		alpha = n%26;

		if (alpha == 0){
			col += 'Z';
			n = n/26 - 1;
		}
		else{
			col += 'A' + alpha - 1;
			n = n/26;
		}
	}

	for (string::reverse_iterator rit=col.rbegin(); rit!=col.rend(); ++rit)
		exl_col += *rit;

	return exl_col;
}

int main (){
	string excel_column;
	int n;

	cout << "Enter the no. to be converted to excel column:" << endl;
	cin >> n;

	cout << "The excel column is: " << convertToTitle (n) << endl;

	return 0;
}
