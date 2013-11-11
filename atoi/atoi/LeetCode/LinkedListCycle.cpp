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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (head == NULL){
            return false;
        }
        
        ListNode *hare, *tortoise;
        hare = tortoise = head;
        
        while (hare != NULL && hare->next != NULL){
            hare = hare->next->next;
            tortoise = tortoise->next;
            
            if (hare == tortoise){
                return true;
            }
        }
        
        return false;
    }
};
