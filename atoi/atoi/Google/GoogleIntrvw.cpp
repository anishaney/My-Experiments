#include <iostream>
#include <string>

using namespace std;

class GoogleIntrvw {
	private:
		float average;
		//string rotStr;
	public:
		GoogleIntrvw (int a){
			average = a;
		}
		float runningAverage (unsigned int n, unsigned int curr_counter);
		int mystrncmp (const char *s1, const char *s2, int n);
		string rotateString (string input, int amt);
};

int GoogleIntrvw :: mystrncmp (const char * s1, const char * s2, int n){
	while (n--){
		if (*s1++ != *s2++)
			return *s1 - *s2;
	}
	return 0;
}

float GoogleIntrvw :: runningAverage (unsigned int n, unsigned int curr_counter){
	this->average = (this->average*(curr_counter - 1) + n)/curr_counter;
	return this->average;
}

string GoogleIntrvw :: rotateString (string input, int amt){
	string output;
	int inIdx, outIdx;

	inIdx = amt % input.length();
	outIdx = 0;

	for (int i = 0; i < input.length(); i++){
		output += input[inIdx];
		if (inIdx == input.length()-1)
			inIdx = -1;
		inIdx++;
		outIdx++;
	}
	cout << output << endl;
	return output;
}

int main (){
	GoogleIntrvw GI (0);
	char s1[20], s2[20];
	int n, amt;
	string input, output;
	cout << "Enter the string to be rotated: " << flush;
	cin >> input;
	cout << "Enter the amt by which string to be rotated: " << flush;
	cin >> amt;
	/*unsigned int num, N;
	float avg;
	cout << "Enter total no. of Numbers to be having running average." << endl;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		avg = GI.runningAverage(num, i);
		cout << "Current average after adding " << num << " is " << avg << endl;
	}
	if (GI.mystrncmp ("foo", "fool", n) == 0)
		cout << "The strings are equal upto " << n << endl;
	else
		cout << "The strings have difference of " << GI.mystrncmp ("foo", "fool", n) << endl;*/

	output = GI.rotateString(input, amt);

	cout << "Rotated string is: " << output << endl;
	return 0;
}

