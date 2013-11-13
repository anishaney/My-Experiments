class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

/*Algorithm: Keep two pointer, one at the start and other at the end. Start checking for the element to be removed and swap it, if found, with the last element, if it is not equal to element. If the end pointer is equal to the element then take next end number.*/

/*Run Time Complexity = O(n)*/
        
        int *i = A, *j = &(A[n-1]), temp, count = 0;

        while (i <= j){
            if (*i == elem){
                if (*j != elem){
                    temp = *i;
                    *i = *j;
                    *j = temp;
                    j--;
                }
                else{
                    j--;
                    continue;
                }
            }
            count++;
            i++;
        }
        return count;
    }
};
