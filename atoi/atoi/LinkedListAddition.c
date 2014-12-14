#include <stdio.h>
#include <stdlib.h>

typedef struct List ListNode;
struct List {
	int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
void print_numbers(ListNode *l1, ListNode *l2);

int main (){
	ListNode *l1 = NULL, *l2 = NULL, *rslt = NULL;
	ListNode *l1_prev = NULL, *l1_next = NULL, *l2_prev = NULL, *l2_next = NULL;
	int count_l1 = 0, count_l2 = 0, i = 0;

	printf("Enter no. of elements in each Linked List for two numbers.\n");
	scanf("%d %d", &count_l1, &count_l2);

	//printf ("The no. of digits in first and second nos are resp: %d %d\n", count_l1, count_l2);

	if (count_l1 > 0){
		l1 = (ListNode *)malloc (sizeof(ListNode));
		printf("Enter unit's digit of first number:\n");
		scanf("%d", &(l1->val));
		l1->next = NULL;
		l1_prev = l1;
	}

	for (i = 1; i < count_l1; i++){
		l1_next = (ListNode *) malloc (sizeof(ListNode));
		printf ("Enter %d digit of first number:\n", i+1);
		scanf("%d", &(l1_next->val));
		l1_prev->next = l1_next;
		l1_next->next = NULL;
		l1_prev = l1_next;
	}

	if (count_l2 > 0){
                l2 = (ListNode *)malloc (sizeof(ListNode));
		printf("Enter unit's digit of second number:\n");
                scanf("%d", &(l2->val));
                l2->next = NULL;
                l2_prev = l2;
        }

        for (i = 1; i < count_l2; i++){
                l2_next = (ListNode *) malloc (sizeof(ListNode));
		printf ("Enter %d digit of second number:\n", i+1);
                scanf("%d", &(l2_next->val));
                l2_prev->next = l2_next;
                l2_next->next = NULL;
                l2_prev = l2_next;
        }

	//print_numbers(l1, l2);
	rslt = addTwoNumbers(l1, l2);
	print_numbers(rslt, l2);

return 0;
}

void print_numbers(ListNode *l1, ListNode *l2){
	ListNode *L1, *L2;

	if (l1 == NULL && l2 == NULL){
		printf ("No Linked List to be displayed.\n");
		return;
	}

	L1 = l1;
	if (L1 != NULL){
		printf ("The first number in reverse order is:\t");
		do{
			printf ("%d->", L1->val);
			L1 = L1->next;
		}while (L1);
		printf ("%p\n", L1);
	}
	else
		printf ("There is no first number.\n");

	L2 = l2;
	if (L2 != NULL){
		printf ("The second number in reverse order is:\t");
		do{
			printf ("%d->", L2->val);
			L2 = L2->next;
		}while (L2);
		printf ("%p\n", L2);
	}
	else
		printf ("There is no second number.\n");

	return;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *rslt_head = NULL, *rslt_next = NULL, *rslt_prev = NULL, *L1 = l1, *L2 = l2;

        unsigned short carry = 0;

        unsigned int result = 0;

        

        if (L1 == NULL && L2 == NULL)

            return NULL;

        else if (L1 == NULL){
		printf ("The first no. is %p\n", L1);

            return L2;}

        else if (L2 == NULL){
		printf ("The second no. is %p\n", L2);

            return L1;}

        

        /* Create head of the result Linked List */
	printf ("%s:%d: Gonna create rslt_head\n", __func__, __LINE__);

        rslt_head = (ListNode *)malloc (sizeof(ListNode));

        if (rslt_head == NULL)

            return NULL;

        result = L1->val + L2->val + carry;

        if (result > 9){

            carry = result/10;

            result = result%10;

        }

        rslt_head->val = result;
	printf("The first val is: %d\t", rslt_head->val);

        rslt_head->next = NULL;

        

        rslt_prev = rslt_head;

        L1 = L1->next;

        L2 = L2->next;

        

        while (L1 && L2){

            /* Create a dynamic memory for the next element */

            rslt_next = (ListNode *)malloc (sizeof(ListNode));

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
		printf ("The next value is: %d\t", rslt_next->val);            

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
			rslt_next->val = carry;
			rslt_prev->next = rslt_next;
			rslt_next->next = NULL;			
		}

            return rslt_head;
	}

        if (L1 == NULL){

            while (L2){

                rslt_next = (ListNode *)malloc (sizeof(ListNode));

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

		printf ("The next value is: %d\t", rslt_next->val);               

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

                rslt_next = (ListNode *)malloc (sizeof(ListNode));

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
		printf ("The next value is: %d\t", rslt_next->val);                 

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
