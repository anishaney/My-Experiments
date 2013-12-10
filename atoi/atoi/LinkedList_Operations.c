#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
//#include <stdbool.h>

#define RECORDS 10

typedef struct animal NODE;

struct animal{
	char name[25];
	char breed[25];
	int age;
	struct animal *next;
}*point, *start, *prior, *loop;

void print_linkedlist(NODE* start);

NODE* insert_at_beg(NODE* start, char* name, char* breed, int age);

NODE* delete_first_node(NODE* start);

NODE* insert_at_end(NODE* start, char* name, char* breed, int age);

NODE* delete_last_node(NODE* start);

NODE* insert_at_nth(NODE* start, int nth_node, char* name, char* breed, int age);

NODE* delete_at_nth(NODE* start, int nth_node);

NODE* reverse(NODE* start);

NODE* reverseII(NODE* start, int, int);

NODE* sortlist(NODE* start);

int HasLoop(NODE* start, int *no_of_nodes_in_LL);

NODE* insertionSort(NODE *start);

NODE *deleteDuplicates(NODE *head);

NODE* remove_nth_node_from_end(NODE *head, int n);

NODE* reordeLinkedList(NODE* head);

int main(){
	
	int index = 0, m, n;
	int Loop = 0, no_of_nodes_in_LL = RECORDS;

	/*initialize arrays to get the values for the nodes*/
	char name[10][20] = {"Dog", "Cat", "Mule", "Horse", "Elephant", "Tiger", "Lion", "Hen", "Peacock", "Tortoise"};
	char breed[10][20] = {"Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed"};

	int age[10] = {4, 5, 6, 7, 8, 9, 10, 50, 53, 100};

	/*Dynamically allocating the memory*/
	start = (NODE *) malloc (sizeof(NODE));

	/*First case is always a special case*/
	strcpy (start->name, "Sheep");
	strcpy (start->breed, "Mix Breed");
	start->age = 3;
	start->next = NULL;

	prior = start; /*giving the head to the next pointer*/

	for (index = 0; index < RECORDS; index++){
		point = (struct animal *) malloc (sizeof(struct animal));

		strcpy (point->name, name[index]);
		strcpy (point->breed, breed[index]);
		point->age = age[index];

		//For checking loops in the Linked_List
		if (index == 2)
			loop = point;
		
		prior->next = point; /*Point earlier node to the current node*/
		
		point->next = NULL; /*point this next to NULL*/
		
		prior = point; /*this is now the prior node*/

		//Making last node point to a intermediate node - making a loop in the LinkedList
		/*if (index == RECORDS-1)
			prior->next = loop;*/
	}

	print_linkedlist(start);

	printf("\n");

	//Loop = HasLoop(start, &no_of_nodes_in_LL);

	/*printf("Enter values of m and n\n");

	scanf("%d %d", &m, &n);*/

	//start = reverseII(start, 1, 10);

	//start = insertionSort(start);

	start = reordeLinkedList(start);

	print_linkedlist(start);

	printf ("\n");

	//start = deleteDuplicates(start);

	//start = remove_nth_node_from_end(start, 10);

	//print_linkedlist(start);

	/*start = insert_at_beg(start, "Deer", "Mixed Breed", 10);
	
	print_linkedlist(start);

	start = insert_at_end(start, "Bear", "Mixed Breed", 14);
	
	print_linkedlist(start);

	start = insert_at_nth(start, 9, "Penguine", "Pure Breed", 30);
	
	print_linkedlist(start);
	
	start = delete_first_node(start);
	
	print_linkedlist(start);

	start = delete_last_node(start);

	print_linkedlist(start);

	start = delete_at_nth(start, 3);

	print_linkedlist(start);

	start = reverse(start);

	print_linkedlist(start);*/

	//start = sortlist(start);

	//print_linkedlist(start);

	/*We should free up the dynamically allocated memory*/
	point = start;

	if(Loop != 1){
	/*Throwing exception because it is trying to free already freed memory*/
		do{
			prior = point->next;
			free(point);
			point = prior;
		}while (prior != NULL);
	}
	else if (Loop == 1)
	{
		for (index = 0; index < no_of_nodes_in_LL; index++){
			prior = point->next;
			free(point);
			point = prior;
		}
	}

	getchar();
	return 0;
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * delete_first_node: L2->L3->L4->L5->NULL
*/

NODE* delete_first_node(NODE *start)
{
	NODE *temp;

	//temp = (struct animal *) malloc(sizeof(struct animal));

	temp = start;

	start = start->next;

	free(temp);

	return(start);
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * delete_last_node: L1->L2->L3->L4->NULL
*/

NODE* delete_last_node(NODE *start)
{
	if (start->next == NULL){
		free(start);
		return NULL;
	}

	else{

		NODE *temp = start, *prev;

		while(temp->next != NULL){
			prev = temp;
			temp = temp->next;
		}

		prev->next = NULL;

		free(temp);
	}

	return(start);
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * delete_at_nth (2): L1->L3->L4->L5->NULL
*/

NODE* delete_at_nth(NODE* start, int nth_node){
	NODE* curr, *curr_next;
	int count = 1;

	curr = start;

	if(nth_node == count){
		start = delete_first_node(start);
		return start;
	}

	while (count < nth_node-1 && curr->next != NULL){
		count++;
		curr = curr->next;
	}

	if (curr == NULL){
		start = delete_last_node(start);
	}
	else
	{
		curr_next = curr->next;
		curr->next = curr_next->next;
		free(curr_next);
	}

	return start;
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * reverse: L5->L4->L3->L2->L1->NULL
*/

NODE* reverse(NODE* start){
	NODE* curr, *prev = NULL;

	curr = start;
	//next2 = curr->next;
	//next3 = next2->next;

	while (curr != NULL){
		NODE* temp = curr->next;
		curr->next = prev;
		//start = curr;
		prev = curr;
		curr = temp;
	}
	//curr->next = prev;
	start = prev;

	return start;
}

void print_linkedlist(NODE* start){
	int i=0;

	if (start == NULL){
		printf("No LinkedList present");
		return;
	}

	point = start;

	do{
		//prior = point->next; /*try putting it below the printf statement*/
		if (i == 15)
			return;
		
		printf("%s is a %s, and is %d years old.\n", point->name, point->breed, point->age);

		point = point->next;

		i++;
	}while (point != NULL);

	return;

	//printf("\n\n");
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * insert_at_beg: L0->L1->L2->L3->L4->L5->NULL
*/

NODE* insert_at_beg(NODE* start, char *name, char *breed, int age){
	NODE* temp;

	temp = (NODE*) malloc(sizeof(NODE));

	if(start == NULL){
		strcpy(temp->name, name);
		strcpy(temp->breed, breed);
		temp->age = age;

		start = temp;
	}

	else{
		strcpy(temp->name, name);
		strcpy(temp->breed, breed);
		temp->age = age;

		temp->next = start;
		start = temp;
	}

	return start;
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * insert_at_end: L1->L2->L3->L4->L5->L6->NULL
*/

NODE* insert_at_end(NODE* start, char* name, char* breed, int age){
	NODE* temp, *head;

	head = start;

	temp = (NODE*) malloc(sizeof(NODE));

	strcpy(temp->name, name);
	strcpy(temp->breed, breed);
	temp->age = age;
	temp->next = NULL;

	if(head == NULL){
		start = temp;
		return start;
	}

	while (head->next != NULL){
		head = head->next;
	}

	head->next = temp;

	return start;
}

/* LinkedList: L1->L2->L3->L4->L5->NULL
 * insert_at_nth(2): L1->L0->L2->L3->L4->L5->NULL
*/

NODE* insert_at_nth(NODE* start, int nth_node, char* name, char* breed, int age){
	NODE* temp;

	NODE* curr, *curr_next;
	int count = 2;

	temp = (NODE*) malloc(sizeof(NODE));

	strcpy(temp->name, name);
	strcpy(temp->breed, breed);
	temp->age = age;
	temp->next = NULL;

	curr = start;

	if(nth_node == count-1){
		start = insert_at_beg(start, name, breed, age);
		return start;
	}

	while (count < nth_node && curr->next != NULL){
		count++;
		curr = curr->next;
	}

	if (curr == NULL){
		start = insert_at_end(start, name, breed, age);
		return start;
	}
	else
	{
		temp->next = curr->next;
		curr->next = temp;
	}

	return start;
}

NODE* sortlist(NODE *root) {

	NODE *middle = NULL, *later = NULL, *parent = NULL, *pwalk2 = NULL;
	if(NULL == root) {
		return root;
	}
	
	middle = root;
	while(middle->next) {
		
		if(middle->age <= middle->next->age)
			middle = middle->next;
		else 
			break;
	}
	
	if(middle->next) {
	 	
	 	
	 	later = middle->next;
		
		/*special case when node goes on top*/
		if(later->age < root->age) {
			if(later->next != NULL)
				middle->next = later->next;
			else {
				middle->next = NULL;
				later->next = middle;
				return later;
			}
			later->next = root;	
			root = later;
			
		}
		
		/*goes in somewhere middle*/
		parent = root;
		while(middle->next) {
			pwalk2 = parent->next;
			while(pwalk2 != middle->next) {
				
				
				later = middle->next;
				if(later->age <= pwalk2->age) {
			
					if(later->next != NULL)
						middle->next = later->next;
					else 
						middle->next = NULL;			
			
					parent->next = later;
					later->next = pwalk2;
					break;
				}
				parent = pwalk2;
				pwalk2 = pwalk2->next;
			}
		
		}
		return root;
	
	} else {
	
		return root;
	}
}

int HasLoop(NODE* start, int *no_of_nodes_in_LL){

	int status = 0, loop_at = 1, index, nodes_not_in_loop = 0;

	if (start == NULL)
		return status;
	else
	{
		NODE *hare = start;
		NODE *tortoise = start;

		NODE* start_loop;
		int count = 0;

		while(hare != NULL && hare->next != NULL)
		{
			hare = hare->next->next;
			tortoise = tortoise->next;

			if (hare == tortoise){
				status = 1;
				start_loop = hare;
				printf("The Linked List has loop\n");
				break;
			}
		}

		if (status){
			tortoise = start_loop->next;
			while (start_loop != tortoise){
				tortoise = tortoise->next;
				count++;
			}

			hare = tortoise = start;
			for (index = 0; index <= count; index++){
				hare = hare->next;
			}

			while (tortoise != hare){
				nodes_not_in_loop++;
				loop_at++;
				hare = hare->next;
				tortoise = tortoise->next;
			}
			printf("The loop in the Linked List starts at node %d\n", loop_at);

			(*no_of_nodes_in_LL) = count + nodes_not_in_loop;
			printf("Number of nodes in the loop are %d\n", *no_of_nodes_in_LL);

			return status;
		}

		printf("The Linked List does not have loop\n");

		(*no_of_nodes_in_LL) = count + nodes_not_in_loop;
		printf("Number of nodes in the loop are %d\n", *no_of_nodes_in_LL);
		
		return status;
	}
}

NODE* reverseII(NODE* root, int m, int n){
	int i = 1;

	NODE *m_prev, *n_prev, *m_node, *n_node, *rev_prev, *rev_first, *rev_next, *m_next, *n_next;
	m_prev = n_prev = m_node = n_node = root;

	if (root == NULL)
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

	while(i < n-m){ //Reversing process starts as we have done it for LinkedList Reversal code (whole LinkedList)
		rev_next = rev_first->next;
		rev_first->next = rev_prev;
		rev_prev = rev_first;
		rev_first = rev_next;
		i++;
	}

	//Connecting the nodes appropriately
	if (m == 1 && n_next != NULL || m == 1 && n_next == NULL){
		root = n_node;
		m_node->next = n_next;
	}
	else{
		m_prev->next = n_node;
		m_node->next = n_next;
	}

	return root;
}

NODE* insertionSort(NODE *start){
	NODE *curr, *temp, *head_start, *head_prev;
	curr = head_start = head_prev = start;

	if (start == NULL){
		return start;
	}
	
	while (curr->next != NULL){
		if (curr->age <= curr->next->age){
			curr = curr->next;
			continue;
		}
		else{
			temp = curr->next;
			curr->next = curr->next->next;
			if (curr == start){
				start = temp;
				temp->next = curr;
			}
			else{
				head_start = start;
				while(head_start->age <= temp->age){
					head_prev = head_start;
					head_start = head_start->next;
				}
				if (head_start == start){
					start = temp;
					temp->next = head_start;
				}
				else {
					head_prev->next = temp;
					temp->next = head_start;
				}
			}
		}
	}
	return start;
}


NODE *deleteDuplicates(NODE *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL || head->next == NULL){
            return head;
        }
        NODE *prev = head, //previous node to the duplicate nodes
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
	    while (curr->age == curr_next->age){
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

	    if (curr == NULL){
		break;
	    }
	    if (curr->next == NULL){
		break;
	    }
	    if (curr->age != curr->next->age){
		prev = curr;
	    }
        }
        return head;
}

NODE* remove_nth_node_from_end(NODE *head, int n){
	if (head == NULL){
		return head;
	}
	
	NODE* n1, *n2, *prev, *temp;
	n1 = n2 = prev = head;
	int i;
	
	for (i = 1; i <= n; i++){
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

NODE* reordeLinkedList(NODE* head){
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return head;

	NODE* fast, *slow, *first, *slow_prev, *slow_next, *first_next, *fast_prev;
	int count = 0, full, half, i;

	fast = slow = first = head;

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

	NODE *temp = NULL;

	while(slow != NULL){
		NODE *node = slow->next;
		slow->next = temp;
		temp = slow;
		slow = node;
	}
	NODE *head1;
	head1 = temp;

	slow_prev->next = NULL;

	//slow = slow_prev->next;

	/*while(first != slow_prev){
		first_next = first->next;
		slow_next = slow->next;
		first->next = slow;
		slow_prev->next = slow_next;
		slow->next = first_next;
		first = first_next;
		slow = slow_next;
	}*/

	while (first != NULL || head1 != NULL){
		NODE *first_next = first->next;
		NODE *slow_next = head1->next;
		first->next = head1;
		head1->next = first_next;
		first = first_next;
		head1 = slow_next; 
	}

	return head;
}
