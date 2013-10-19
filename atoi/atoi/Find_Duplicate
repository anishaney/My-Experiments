#include <iostream>

using namespace std;


/*Using extra O(n) space*/
bool HasDuplicate(int arr[], int length){
	int val;

	bool present[length]; //Create boolean array to mark the value as traversed or not

	for (int i = 0; i < length; i++){
		val = arr[i];
		if (!present[val]) //If the value has not been traversed then mark it as true
			present[val] = true;
		else //else there's a duplicate
			return true;
	}
	
	return false;
}

/*Using swapping technic space - Check if the element at position i is rightly placed at the position, for example the number at position 2 should be 2. If not then swap it with the element at position arr[i].*/
bool HasDuplicate1(int arr[], int length){
	int val;

	for (int i = 0; i < length; i++){
		if (arr[i] != i){
			do{
				if (arr[arr[i]] == arr[i])
					return true;
				swap(arr[arr[i]], arr[i]);
			}while(arr[i] != i);
		}
	}
	
	return false;
}

int main(){
	int arr[] = {0, 1, 2, 3, 4, 5};
	int arr1[] = {0, 1, 5, 3, 4, 5};

	int length = sizeof(arr)/sizeof(arr[0]);

	bool duplicate = HasDuplicate1(arr, length);
	if (duplicate)
		cout << "The array has duplicate." << endl;
	else
		cout << "The array does not have duplicate." << endl;

	duplicate = HasDuplicate1(arr1, length);
	if (duplicate)
		cout << "The array has duplicate." << endl;
	else
		cout << "The array does not have duplicate." << endl;

	return 0;
}
