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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
            return head;
        
        ListNode *curr = head, *rmve, *p = curr->next;
        while (curr != NULL && p != NULL){
            if (curr->val == p->val){
                rmve = p;
                p = p->next;
                curr->next = p;
                free(rmve);
            }
            else{
                curr = p;
                p = curr->next;
            }
        }
        return head;
    }
};
