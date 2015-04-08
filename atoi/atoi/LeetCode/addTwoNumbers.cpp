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

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *rslt_head = NULL, *rslt_next = NULL, *rslt_prev = NULL, *L1 = l1, *L2 = l2;

        unsigned short carry = 0;

        unsigned int result = 0;

        

        if (L1 == NULL && L2 == NULL)

            return NULL;

        else if (L1 == NULL)

            return L2;

        else if (L2 == NULL)

            return L1;

        

        /* Create head of the result Linked List */

        rslt_head = (ListNode *)malloc (sizeof(struct ListNode));

        if (rslt_head == NULL)

            return NULL;

        result = L1->val + L2->val + carry;

        if (result > 9){

            carry = result/10;

            result = result%10;

        }

        rslt_head->val = result;

        rslt_head->next = NULL;

        

        rslt_prev = rslt_head;

        L1 = L1->next;

        L2 = L2->next;

        

        while (L1 && L2){

            /* Create a dynamic memory for the next element */

            rslt_next = (ListNode *)malloc (sizeof(struct ListNode));

            if (rslt_next == NULL)

                return NULL;

            

            result = L1->val + L2->val + carry;

            if (result > 9){

                carry = result/10;

                result = result%10;

            }

            else

                carry = 0;



            rslt_next->val = result;

            

            L1 = L1->next;

            L2 = L2->next;

            

            rslt_prev->next = rslt_next;

            rslt_next->next = NULL;

            rslt_prev = rslt_next;

        }

        

        if (L1 == NULL && L2 == NULL){

            if (carry){

                rslt_next = (ListNode *) malloc (sizeof(ListNode));

                if (rslt_next == NULL)

                    return rslt_head;

                result = 

                rslt_next->val = carry;

                rslt_prev->next = rslt_next;

                rslt_next->next = NULL;

            }

            return rslt_head;

        }

        if (L1 == NULL){

            while (L2){

                rslt_next = (ListNode *)malloc (sizeof(struct ListNode));

                if (rslt_next == NULL)

                    return NULL;

                

                result = L2->val + carry;

                if (result > 9){

                    carry = result/10;

                    result = result%10;

                }

                else

                    carry = 0;



                rslt_next->val = result;

                

                L2 = L2->next;

                

                rslt_prev->next = rslt_next;

                rslt_next->next = NULL;

                rslt_prev = rslt_next;

            }

            if (carry){

                rslt_next = (ListNode *) malloc (sizeof(ListNode));

                if (rslt_next == NULL)

                    return rslt_head;

                rslt_next->val = carry;

                rslt_prev->next = rslt_next;

                rslt_next->next = NULL;

            }

            

            return rslt_head;

        }

        if (L2 == NULL){

            while (L1){

                rslt_next = (ListNode *)malloc (sizeof(struct ListNode));

                if (rslt_next == NULL)

                    return NULL;

                

                result = L1->val + carry;

                if (result > 9){

                    carry = result/10;

                    result = result%10;

                }

                else

                    carry = 0;



                rslt_next->val = result;

                

                L1 = L1->next;

                

                rslt_prev->next = rslt_next;

                rslt_next->next = NULL;

                rslt_prev = rslt_next;

            }

            if (carry){

                rslt_next = (ListNode *) malloc (sizeof(ListNode));

                if (rslt_next == NULL)

                    return rslt_head;

                rslt_next->val = carry;

                rslt_prev->next = rslt_next;

                rslt_next->next = NULL;

            }

            

            return rslt_head;

        }

    }

};
