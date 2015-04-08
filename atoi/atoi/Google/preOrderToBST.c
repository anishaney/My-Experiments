//{12,6,2,11,19,17,14,15,18}

#include <stdio.h>
#include <stdlib.h>

struct BSTNode{
	int val;
	struct BSTNode *left;
	struct BSTNode *right;
};

struct BSTNode * add_new_node (int data){
	struct BSTNode * new_node = (struct BSTNode *) malloc (sizeof (struct BSTNode));

	new_node->val = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

struct BSTNode * ConstructBST (int pre[], int *preIdx, int low, int high, int size){
	int i;
	
	if (*preIdx >= size || low > high)
		return NULL;

	struct BSTNode * root = add_new_node (pre[*preIdx]);
	*preIdx = *preIdx + 1;

	if (low == high)
		return root;

	for (i = low; i <= high; i++){
		if (root->val < pre[i])
			break;
	}

	static int O = 0;
	printf("Complexity parameter O is %d for pre[%d] %d\n", O++, *preIdx, pre[*preIdx]);

	root->left = ConstructBST(pre, preIdx, *preIdx, i-1, size);
	root->right = ConstructBST(pre, preIdx, i, high, size);

	return root;
}

void printInorder (struct BSTNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->val);
    printInorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {40, 35, 20, 10, 3, 12, 15, 38, 53, 45, 42, 50, 55, 70}, preIdx = 0;
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct BSTNode *root = ConstructBST(pre, &preIdx, 0, size-1, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    printf("\n");
 
    return 0;
}
