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

    int get_count (ListNode *head){
        ListNode *current = head;
        int count = 0;
        
        while (current != NULL){
            count++;
            current = current->next;
        }
        
        return count;
    }
    
    ListNode *_getIntersectionNode (int d, ListNode *headLarge, ListNode *headSmall){
        ListNode *current1 = headLarge, *current2 = headSmall;
        
        for (int i = 0; i < d; i++){
            if (current1 == NULL){
                return NULL;
            }
            current1 = current1->next;
        }
        
        while (current1 != NULL && current2 != NULL){
            if (current1 == current2)
                return current1;
            
            current1 = current1->next;
            current2 = current2->next;
        }
        
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL){
            return NULL;
        }
        
        int countA, countB, diff;
        
        countA = get_count(headA);
        countB = get_count(headB);
        
        diff = abs(countA - countB);
        
        if (countA >= countB)
            return _getIntersectionNode (diff, headA, headB);
        else
            return _getIntersectionNode (diff, headB, headA);
    }
};
