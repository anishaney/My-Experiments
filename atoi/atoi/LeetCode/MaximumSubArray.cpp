class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int curr_sum = A[0];
        int max_sum = A[0], startindexnow = -1, stopindexmax = -1, startindexmax = -1;
        
        for (int i=1; i<n; i++){
            if(curr_sum < 0){
                curr_sum = A[i];
            }
            else{
                curr_sum += A[i];
            }
            if(max_sum < curr_sum){
                max_sum = curr_sum;
            }
        }
        return max_sum;
    }
};
