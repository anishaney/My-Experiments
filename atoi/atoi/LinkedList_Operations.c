#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define RECORDS 6

typedef struct animal NODE;

struct animal{
	char name[25];
	char breed[25];
	int age;
	struct animal *next;
}*point, *start, *prior;

void print_linkedlist(NODE* start);

NODE* insert_at_beg(NODE* start, char* name, char* breed, int age);

NODE* delete_first_node(NODE* start);

NODE* insert_at_end(NODE* start, char* name, char* breed, int age);

NODE* delete_last_node(NODE* start);

NODE* insert_at_nth(NODE* start, int nth_node, char* name, char* breed, int age);

NODE* delete_at_nth(NODE* start, int nth_node);

NODE* reverse(NODE* start);


int main(){
	
	int index = 0;

	/*initialize arrays to get the values for the nodes*/
	char name[10][20] = {"Dog", "Cat", "Mule", "Horse", "Elephant", "Tiger"};
	char breed[10][20] = {"Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed", "Mixed Breed"};

	int age[10] = {4, 5, 7, 22, 50, 17};

	/*Dynamically allocating the memory*/
	start = (NODE *) malloc (sizeof(NODE));

	/*First case is always a special case*/
	strcpy (start->name, "Sheep");
	strcpy (start->breed, "Mix Breed");
	start->age = 6;
	start->next = NULL;

	prior = start; /*giving the head to the next pointer*/

	for (index = 0; index < RECORDS; index++){
		point = (struct animal *) malloc (sizeof(struct animal));

		strcpy (point->name, name[index]);
		strcpy (point->breed, breed[index]);
		point->age = age[index];
		prior->next = point; /*Point earlier node to the current node*/

		point->next = NULL; /*point this next to NULL*/

		prior = point; /*this is now the prior node*/
	}

	print_linkedlist(start);

	start = insert_at_beg(start, "Deer", "Mixed Breed", 10);
	
	printf("\n\n");

	print_linkedlist(start);

	start = insert_at_end(start, "Bear", "Mixed Breed", 14);
	
	printf("\n\n");

	print_linkedlist(start);

	start = insert_at_nth(start, 9, "Penguine", "Pure Breed", 30);
	
	printf("\n\n");

	print_linkedlist(start);
	
	start = delete_first_node(start);
	
	printf("\n\n");

	print_linkedlist(start);

	start = delete_last_node(start);

	printf("\n\n");

	print_linkedlist(start);

	start = delete_at_nth(start, 3);

	printf("\n\n");

	print_linkedlist(start);

	start = reverse(start);

	printf("\n\n");

	print_linkedlist(start);

	//point = start;

	/*We should free up the dynamically allocated memory*/
	point = start;

	do{
		prior = point->next;
		free(point);
		point = prior;
	}while (prior != NULL);

	getch();
	return 0;
}

NODE* delete_first_node(NODE *start)
{
	NODE *temp;

	//temp = (struct animal *) malloc(sizeof(struct animal));

	temp = start;

	start = start->next;

	free(temp);

	return(start);
}

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
	point = start;
	do{
		//prior = point->next; /*try putting it below the printf statement*/
		
		printf("%s is a %s, and is %d years old.\n", point->name, point->breed, point->age);

		point = point->next;
	}while (point != NULL);
}

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