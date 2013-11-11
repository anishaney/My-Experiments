class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = m, j = n, k;
    	while(i > 0 || j > 0){
    		if (j == 0){
    			while (i > 0){
    				A[i+j-1] = A[i-1];
    				i--;
    			}
    		}
    		else if (i == 0){
    			while (j > 0){
    				A[i+j-1] = B[j-1];
    				j--;
    			}
    		}
    		else if(A[i-1] > B[j-1]){
    			A[i+j-1] = A[i-1];
    			i--;
    		}
    		else{
    			A[i+j-1] = B[j-1];
    			j--;
    		}
    	}
    }
};
