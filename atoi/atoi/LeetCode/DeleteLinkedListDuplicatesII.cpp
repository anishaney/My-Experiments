/*Algorithm: Keep on checking for all the duplicate nodes and keep a track of previous non-duplicate node (before the set of duplicate nodes) and the first node of the set of duplicate nodes.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

	//if the linkedlist contains no elements or just one element.
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *prev = head, //previous node to the duplicate nodes
    	*rem, //node to be freed
    	*curr = head, //the curr node in the duplicate nodes
    	*curr_next, //next node in duplicate/non-duplicate nodes
    	*first; //starting node of the duplicate node

        int count, i; //count for the no. of duplicate nodes
        
        while (curr){
            count = 1; //initialize it to 1 so that when nodes are not same the count will give us no. of duplicate nodes

    	    //point to the next noide
    	    curr_next = curr->next;
    
    	    i = 0;

	    //Keep on checking for the duplication of the nodes.
    	    while (curr->val == curr_next->val){
    		    if (!i){
    			    i++;
    			    first = curr;
    		    }
        		count++;
        		curr = curr_next;
        		curr_next = curr->next;
        		if (curr_next == NULL){
        			break;
        		}
    	    }
            curr = curr_next;

	    //this logic runs when there are duplicate nodes.
            if (count > 1){
                if (first == head){
                    head = curr;
                }
    		    else{
    		        prev->next = curr;
    		    }
                for (i = 0; i < count; i++){
                    rem = first;
                    first = first->next;
                    free(rem);
                }
            }
    	    
	    //When the last node is a duplicate
    	    if (curr == NULL){
    		    break;
    	    }

	    //When the last node is not a duplicate
    	    if (curr->next == NULL){
    		    break;
    	    }

	    //Keep a track of the previous non-duplicate node
    	    if (curr->val != curr->next->val){
    		    prev = curr;
    	    }
        }
        return head;
    }
};
