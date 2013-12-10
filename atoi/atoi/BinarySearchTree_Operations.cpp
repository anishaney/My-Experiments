#include <iostream>
//#include <conio>
#include <algorithm>

using namespace std;

class BinarySearchTree{
private:
	struct tree_node{
		int data;
		struct tree_node *right;
		struct tree_node *left;
	};
	tree_node* root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	bool isEmpty() const {return (root==NULL);}
	void insert(int);
	void remove(int);
	void preorder(tree_node*);
	void print_preorder();
	void inorder(tree_node*);
	void print_inorder();
	void postorder(tree_node*);
	void print_postorder();
	int Max_Depth(tree_node*, int);
	void Max_Depth_print();
};

void BinarySearchTree :: insert(int num){
	tree_node* node = new tree_node;

	tree_node* parent;

	node->data = num;
	node->left = NULL;
	node->right = NULL;
	parent = NULL;

	/*Is this tree empty*/
	if (isEmpty()){
		cout << "Tree is empty." <<endl;
		root = node;
	}
	else
	{
		tree_node* curr;
		curr = root;

		//Find the Node's parents

		while (curr){
			parent = curr;
			if (node->data > curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}

		if(node->data < parent->data)
			parent->left = node;
		else
			parent->right = node;
	}
}

void BinarySearchTree :: remove(int num){
	//Locate the element
	bool present = false;

	if (isEmpty()){
		cout << "The tree is Empty. So can't delete the data." << endl;
		return;
	}

	tree_node* curr, *parent;
	curr = root;
	
	while(curr != NULL){
		if (curr->data == num){
			present = true;
			break;
		}
		else
		{
			parent = curr;
			if (curr->data <= num)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}

	if (!present){
		cout << "The data is not present in the BST." << endl;
		return;
	}

	/*3 Cases:
	1. Node with no child nodes.
	2. Node with two children.
	3. Node with one child./*

	/* We will start with 3rd case - Node with one child */

	if((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)){

		if (curr->left == NULL && curr->right != NULL){
			if (parent->left == curr){
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else
		{
			if (parent->left == curr){
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}

	/*Consider 1st case: Leaf Node.*/

	if (curr->left == NULL && curr->right == NULL){
		if (parent->left == curr){
			parent->left = NULL;
			delete curr;
		}
		else
		{	
			parent->right = NULL;
			delete curr;
		}
		return;
	}

	/*Consider 3rd case: Node having two children*/

	if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		 		 		 		 curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
		 		 		    curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}


void BinarySearchTree::print_inorder(){
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p){
	if(p!=NULL){
		if (p->left)
			inorder(p->left);
		cout << " "<<p->data << " ";
		if (p->right)
			inorder(p->right);
	}
	else
		return;
}

void BinarySearchTree::print_preorder(){
	preorder(root);
}

void BinarySearchTree::preorder(tree_node* p){
	if(p!=NULL){
		cout << " "<<p->data << " ";
		if (p->left)
			preorder(p->left);
		if (p->right)
			preorder(p->right);
	}
	else
		return;
}

void BinarySearchTree::print_postorder(){
	postorder(root);
}

void BinarySearchTree::postorder(tree_node* p){
	if(p!=NULL){
		if (p->left)
			postorder(p->left);
		if (p->right)
			postorder(p->right);
		cout << " "<<p->data << " ";
	}
	else
		return;
}

void BinarySearchTree::Max_Depth_print(){
	cout << Max_Depth(root, 1);
}

int BinarySearchTree::Max_Depth(tree_node* p, int Level){
	static int depth = 0;
	if (p == NULL){	
		return 0;
	}
	if (p != NULL){
		if(Level > depth)
			depth = Level;
		Max_Depth(p->left, Level+1);
		Max_Depth(p->right, Level+1);
	}
	return depth;
} 


int main(){
	BinarySearchTree b;

	int num[10];
	int Level = 1, depth;

	cout << "Enter number to be inserted" << endl;
	for (int i=0; i<10; i++){
		cin >> num[i];
		b.insert(num[i]);
	}

	//for (int i=0; i<10; i++){
		
	//}
	
	b.print_inorder();
	cout << endl;
	b.print_preorder();

	b.remove(num[6]);

	b.print_inorder();
	cout << endl;
	b.print_preorder();

	cout << endl;

	b.Max_Depth_print();

	return 0;
}
