#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int main_idx;
	int aux_idx;
	int *main_stack;
	int *aux_stack;
    int top;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
	stack->size = maxSize;
	stack->main_idx = 0;
	stack->aux_idx = 0;
    stack->main_stack = (int *) malloc ((stack->size)*(sizeof(int)));
    //stack->aux_stack = (int *) malloc (stack->size*(sizeof(int)));
	printf ("size %d, main_idx %d and sizeof(main_stack) %d\n", stack->size, stack->main_idx, sizeof(stack->main_stack));
}

void minStackPush(MinStack *stack, int element) {
	printf ("main_idx %d and sizeof(main_stack) %d\n", stack->main_idx, sizeof(stack->main_stack));
    if (stack->main_idx == stack->size)
		return;

	stack->main_stack[(stack->main_idx)++] = element;

	/*if (stack->aux_idx == 0)
		stack->aux_stack[(stack->aux_idx)++] = element;
	else if (stack->aux_stack[(stack->aux_idx)] < element)
			stack->aux_idx++;
		 else
			stack->aux_stack[(stack->aux_idx)++] = element;*/
		
}

int minStackPop(MinStack *stack) {
    if (stack->main_idx == 0)
		return;

	return stack->main_stack[--(stack->main_idx)];
}

int minStackTop(MinStack *stack) {
    if (stack->main_idx == 0)
		return;

	return (stack->main_stack[stack->main_idx]);
}

int minStackGetMin(MinStack *stack) {
	if (stack->aux_stack == 0)
		return;

	return stack->aux_stack[(stack->aux_idx)];
}

void minStackDestroy(MinStack *stack) {
    free(stack->main_stack);
	free(stack->aux_stack);
}


int main(){
	MinStack *new_stack;
	int maxSize, i, element;

	i = 0;

	printf("Enter the size of the stack:\n");
	scanf ("%d\n", &maxSize);

	minStackCreate(new_stack, maxSize);
	printf ("main_idx %d and sizeof(main_stack) %d\n", new_stack->main_idx, sizeof(new_stack->main_stack));

	while(i < maxSize){
		scanf("%d\n", &element);
		printf("%d\n", element);
		minStackPush(new_stack, element);
		i++;
	}

	printf("The top element is %d\n", minStackTop(new_stack));
	printf("Popping element %d\n", minStackPop(new_stack));
	//printf("The min element is %d\n", minStackGetMin(new_stack));

	minStackPop(new_stack);
	minStackPop(new_stack);

	//printf("Now the min element is %d\n", minStackGetMin(new_stack));

	return 0;
}
