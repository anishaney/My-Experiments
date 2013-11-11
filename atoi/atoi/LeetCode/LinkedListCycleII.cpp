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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int count = 1;
        
        if (head == NULL){
            return head;
        }
        
        ListNode *hare, *tortoise;
        hare = tortoise = head;
        
        while (hare != NULL && hare->next != NULL){
            hare = hare->next->next;
            tortoise = tortoise->next;
            
            if (hare == tortoise){
                hare = hare->next;
                while (tortoise != hare){
                    count++;
                    hare = hare->next;
                }
                tortoise = head;
                for (int i = 0; i < count; i++){
                    hare = hare->next;
                }
                
                while(hare != tortoise){
                    hare = hare->next;
                    tortoise = tortoise->next;
                }
                return hare;
            }
        }
        return NULL;
    }
};
