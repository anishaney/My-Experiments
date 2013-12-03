/*Algorithm: Put a 'for' loop to reach the nth node from the start. Then using a 'while' loop, check till the nth node (from start) is NULL and increment another node from the start. Once, the nth node (from start) reaches end of the LinkedList, the second node is at position 'n' from the end of the LinkedList.
*/

/*Complexity: O(n)
*/


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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL){
		    return head;
    	}
    	
    	ListNode* n1, *n2, *prev, *temp;
    	n1 = n2 = prev = head;
    	
    	for (int i = 1; i <= n; i++){
    		if(n1 != NULL){ //If n is greater than the no. of nodes in the LinkedList return the head
    			n1 = n1->next;
    		}
    		else
    			return head;
    	}
    
    	while (n1){
    		prev = n2;
    		n2 = n2->next;
    		n1 = n1->next;
    	}
    
    	if (n2 == head){
    		temp = n2;
    		head = n2->next;
    		free(n2);
    	}
    	else{
    		temp = n2;
    		prev->next = n2->next;
    		free(temp);
    	}
    
    	return head;
    }
};
