/*Algorithm: Keep three pointers to find the duplicates (nodes having same val value). Traverse through the linked list and keep checking the value of the current node->val if equal to the node.next->val. If so, remove the node.next and jump to the subsequent node. If not equal then change the first node to the node.next and subsequent node.*/

/*Complexity: O(n)*/


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

	//Check if Linked List is NULL
        if(head == NULL)
            return head;
        
        ListNode *curr = head, *rmve, *p = curr->next;

        while (curr != NULL && p != NULL){
            if (curr->val == p->val){ //If equal
                rmve = p; //put current node to a removal pointer
                p = p->next;//point to the next node.
                curr->next = p;//join current node to the next node
                free(rmve);//free the memory allocated to the duplicate node.
            }
            else{//If not equal
                curr = p; //change current node to point to the next node
                p = curr->next;//and subsequent node
            }
        }
        return head;
    }
};
