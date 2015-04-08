#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct BSTNode * ConstructBST (int pre[], int *preIdx, int key, int min, int max, int size){
	if (*preIdx >= size)
		return NULL;

	struct BSTNode * root = NULL;

	if (key > min && key < max){
		static int O = 0;
		printf("Complexity parameter O is %d for pre[%d] %d\n", O++, *preIdx, pre[*preIdx]);

		root = add_new_node (key);
		*preIdx = *preIdx + 1;

		if (*preIdx < size){
			root->left = ConstructBST(pre, preIdx, pre[*preIdx], min, key, size);
			root->right = ConstructBST(pre, preIdx, pre[*preIdx], key, max, size);
		}
	}

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
 
    struct BSTNode *root = ConstructBST(pre, &preIdx, pre[preIdx], INT_MIN, INT_MAX, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    printf("\n");
 
    return 0;
}
