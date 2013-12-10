/* Algorithm: Find the middle of the Linked List using fast and slow pointers (fast moving 2 nodes and slow 1 node each iteration). Depending  *upon the odd and even no. of nodes in the Linked List, the middle node of the List should be adjusted accordingly. Reverse the second half of *the List and insert each element of the reversed List in the first half of the List.
*/

/* Complexity: O(n)
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
    void reorderList(ListNode *head) {

    	ListNode* fast, *slow, *first, *slow_prev, *slow_next, *first_next, *fast_prev;
    	int count = 0, full, half, i;
    
    	fast = slow = first = head;
    	
        if (head == NULL || head->next == NULL || head->next->next == NULL){
		    return;
        }
    
    	while(fast != NULL && fast->next != NULL){
    		count++;
    		slow_prev = slow;
    		slow = slow->next;
    		fast_prev = fast;
    		fast = fast->next->next;
    	}
    	
    	if (fast == NULL){
    		full = count*2;
    		half = count;
    	}
    	else if (fast->next == NULL){
    		full = count*2 + 1;
    		half = count+1;
    		slow_prev = slow_prev->next;
    	}
    
    	//head = reverseII(head, half+1, full);
    
    	ListNode *temp = NULL;
    
    	while(slow != NULL){
    		ListNode *node = slow->next;
    		slow->next = temp;
    		temp = slow;
    		slow = node;
    	}
    	ListNode *head1;
    	head1 = temp;
    
    	slow_prev->next = NULL;
    
    	while (first != NULL || head1 != NULL){
    		ListNode *first_next = first->next;
    		ListNode *slow_next = head1->next;
    		first->next = head1;
    		head1->next = first_next;
    		first = first_next;
    		head1 = slow_next; 
    	}
    
    	return;
    }
};
