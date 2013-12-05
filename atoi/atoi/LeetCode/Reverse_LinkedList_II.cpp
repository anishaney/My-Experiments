/** Algorithm: Traverse through LinkedList and find out the mth and nth nodes. Get the next and previous nodes of both. Now run a while loop for the (n-m) iterations and reverse the LinkedList between mth and nth nodes.
*/

/* Complexity: O(n+m), where n and m are the input arguments*/

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 1;

    	ListNode *m_prev, *n_prev, *m_node, *n_node, *rev_prev, *rev_first, *rev_next, *m_next, *n_next;
    	m_prev = n_prev = m_node = n_node = head;
    
    	if (head == NULL)
    		return NULL;
    
    	for (i = 1; i < n; i++){
    		n_prev = n_node; //No need of this line, but keeping it just in case required for future use.
    		n_node = n_node->next;
    	}
    
    	for (i = 1; i < m; i++){
    		m_prev = m_node; //Required since we need to connect this node to the nth node's next.
    		m_node = m_node->next;
    	}
    
    	m_next = m_node->next; //Required to start the reversing process.
    	n_next = n_node->next; //Required to connect the LinkedList back.
    
    	rev_prev = m_node;
    	rev_first = m_next;
    
    	i = 0;

	//Reversing process starts as we have done it for LinkedList Reversal code (whole LinkedList)    
    	while(i < n-m){ //Run iteration for (n-m) times
    		rev_next = rev_first->next;
    		rev_first->next = rev_prev;
    		rev_prev = rev_first;
    		rev_first = rev_next;
    		i++;
    	}
    
    	//Connecting the nodes appropriately
    	if (m == 1){ //If the first node to be reversed is the head node then replace head with the mth node.
    		head = n_node;
    		m_node->next = n_next;
    	}
    	else{
    		m_prev->next = n_node;
    		m_node->next = n_next;
    	}
    
    	return head;
    }
};
