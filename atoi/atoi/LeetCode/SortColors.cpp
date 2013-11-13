#include <iostream>

using namespace std;

void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int *fwd, *bkwd;
        int temp; //For swapping the elements
        int B[3] = {0, 1, 2}; //Containing the distinct values of the Array
        
        fwd = A; //Placing at the start of the array
        bkwd = &(A[n-1]); //Placing at the end of the array
        
        for (int i=0; i<2; i++){//Need to run for just two values 0 & 1
            while(fwd < bkwd){
                if (*fwd != B[i]){
		    //Swap the elements
                    if(*bkwd == B[i]){
                        temp = *fwd;
                        *fwd = *bkwd;
                        *bkwd = temp;
                    }
                    else{//If not 0 or 1 i.e B[i] decrement 'bkwd' pointer
                        bkwd--;
                        continue;
                    }
                }
                fwd++; //Increment the 'fwd' pointer to access the new location
            }
	    bkwd = &(A[n-1]); //Set the last element back to the end
        }
}

int main(){
	int A[10] = {0,1,1,0,2,1,0,0,2,1};
	int n = sizeof(A)/sizeof(A[0]);

	for (int i=0; i<n; i++){
		cout << A[i] << "\t";
	}

	cout << endl;

	sortColors(A, n);

	for (int i=0; i<n; i++){
		cout << A[i] << "\t";
	}

	cout << endl;

	return 0;
}
