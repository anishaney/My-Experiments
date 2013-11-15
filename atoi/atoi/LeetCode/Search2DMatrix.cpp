/*Algorithm: Get the rows and column lengths of the 2D matrix, m x n. Check, using while loop in which row the target element could be found. Once row is selected, apply Binary Search algorithm to the sorted row to check if target element is present or not.*/

/*Complexity: O(m*log n) */


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

	//Get the no. of rows and columns.
        int m = matrix.size();
        int n = matrix[0].size(), i = 0;
        
	//Check in which row the target could be found
        while (i < m){
            if (target < matrix[i][0]){
                i--;
                break;
            }
            if (target == matrix[i][0]){
                return true;
            }
            if (target == matrix[i][n-1]){
                return true;
            }
            i++;
        }
        if (i < 0){
            return false;
        }
        else if (i == m){
            if (target > matrix[m-1][n-1]){//Checking for first element of (m-1)th row
                return false;
            }
            else if (target == matrix[m-1][n-1]){//Checking for last element
                return true;
            }
            i--;
        }

	//Applying Binary Search algorithm to the selected row.        
        int start = 0, end = n-1, mid = start/2 + end/2;

        while (start <= end){
            if (matrix[i][mid] == target){
                return true;
            }
            else if (target < matrix[i][mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            if (start == end){
                mid = end;
            }
            else{
                mid = start/2 + end/2;
            }
        }
        return false;
    }
};
