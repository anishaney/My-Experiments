#include <iostream>

using namespace std;

class FibLastDigPair{
	private:
		unsigned int curr;
		unsigned int prev;
	public:
		void Outputpairs(int n);
		void printPairs(int a, int b);
};

void FibLastDigPair :: printPairs (int a, int b){
	cout << "[" << a << "," << b << "]" << endl;
}

void FibLastDigPair :: Outputpairs (int n){
	unsigned int temp;
	this->curr = this->prev = 1;
	for (int i = 0; i < n; i++){
		cout << i << ". ";
		printPairs (this->curr % 10, this->prev % 10);
		temp = this->curr;
		this->curr += this->prev;
		this->prev = temp;
	}
}

int main (){
	FibLastDigPair fibPair1;
	int n;
	cout << "Enter number of pairs to be displayed: " << endl;
	cin >> n;
	fibPair1.Outputpairs (10);
	return 0;
}
