/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL){
            return head;
        }
        
        RandomListNode *original = head, *head2, *copy1;
        
        while(original != NULL){
            RandomListNode *copy = new RandomListNode(original->label);
            copy->next = original->next;
            original->next = copy;
            original = original->next->next;
        }
        original = head;
        while(original != NULL){
            if(original->random == NULL){
                original->next->random = NULL;
            }
            else{
                original->next->random = original->random->next;
            }
            original = original->next->next;
        }
        original = head;
        copy1 = head->next;
        head2 = copy1;
        
        while(original != NULL){
            original->next = original->next->next;
            if (copy1->next != NULL){
                copy1->next = copy1->next->next;
            }
            original = original->next;
            copy1 = copy1->next;
        }
        return head2;
    }
};
