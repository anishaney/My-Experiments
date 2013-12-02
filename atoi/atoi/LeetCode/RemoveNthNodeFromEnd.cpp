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
    		if(n1 != NULL){
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
