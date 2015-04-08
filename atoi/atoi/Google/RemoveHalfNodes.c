struct TNode *RemoveHalfNodes (struct TNode *root){
	struct TNode *current = root;
	if (root == NULL)
		return NULL;
	
	current->left = RemoveHalfNodes(current->left);
	current->right = RemoveHalfNode(current->right);

	if (current->left == NULL && current->right == NULL)
		return current;

	if (current->left == NULL){
		struct TNode * new_current = current->right;
		free (current);
		return new_current;
	}
	if (current->right == NULL){
		struct TNode * new_current = current->left;
		free (current);
		return new_current;
	}

	return current;
}
