/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL){
            return head;
        }
        ListNode *curr, *prev, *temp, *start;
        
        prev = start = head;
        curr = prev->next;
        
        /*if (curr != NULL){
            temp = prev;
            prev = curr;
            curr = temp;
            start = curr;
        }*/
        
        while(curr != NULL && curr->next != NULL){
            prev = prev->next;
            curr = prev->next;
            
        }
    }
};
