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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        
        ListNode* prev, *curr, *other, *start, *temp;
        
        if (l1->val <= l2->val){
            curr = start = l1;
            other = l2;
        }
        else{
            curr = start = l2;
            other = l1;
        }
        while(curr != NULL || other != NULL){
            if (curr == NULL){
                prev->next = other;
                break;
            }
            if (curr->val <= other->val){
                prev = curr;
                curr = curr->next;
                continue;
            }
            prev->next = other;
            temp = curr;
            curr = other;
            other = temp;
        }
        return start;
    }
};
