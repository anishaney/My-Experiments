#include <iostream>

using namespace std;

int searchInsert(int  A[], int n, int target){
	int start = 0, end = n-1;
    	int mid = end/2 + start/2;
    	while (start < end){
    		if (!mid)
    			break;
    		if (A[mid] == target)
    			return mid;
    		else if (A[mid] > target)
    			end = mid - 1;
    		else
    			start = mid + 1;
    		if (start == end)
    		    mid = end;
    		else
    		    mid = start/2 + end/2;
    	}
    	if (A[mid] == target)
		    return mid;
    	if (A[end] < target)
    		return end+1;
    	else{
    		if(start == 0 && A[start] < target)
    			return start+1;
    		else if (A[start] > target)
    			return start;
    		return start+1;
    	}
    }
}

int main(){
	int A[2] = {1,3}, n, target, index;
	cin >> target;
	n = sizeof(A)/sizeof(A[0]);

	index = searchInsert(A, n, target);
	cout << index << endl;
	
	return 0;
}
