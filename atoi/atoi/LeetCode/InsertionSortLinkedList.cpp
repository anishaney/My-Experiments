/*Algorithm: Start from the first node and check if next node is less than the current. If so, then check for all the nodes, from 1st node, if the smaller value node is less than those nodes. If so then insert it in between.*/

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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
    
    	if (head == NULL){//Check if Linked List is null
    		return head;
    	}

        ListNode *curr, *temp, *head_start, *head_prev;
    	curr = head_start = head_prev = head;
    	
    	while (curr->next != NULL){
    		if (curr->val <= curr->next->val){//Find the next smaller value node
    			curr = curr->next;
    			continue;
    		}
    		else{
    			temp = curr->next;
    			curr->next = curr->next->next;
    			if (curr == head){
    				head = temp;
    				temp->next = curr;
    			}
    			else{
    				head_start = head;
    				while(head_start->val <= temp->val){
    					head_prev = head_start;
    					head_start = head_start->next;
    				}
    				if (head_start == head){
    					head = temp;
    					temp->next = head_start;
    				}
    				else {
    					head_prev->next = temp;
    					temp->next = head_start;
    				}
    			}
    		}
    	}
	    return head;
    }
};
