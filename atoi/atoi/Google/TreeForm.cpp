class Tree{
   public:
	int key;
	Tree right;
	Tree left;
	Tree (int key){
		this.key = key;
		this.right = NULL;
		this.left = NULL;
	}
	Tree FormTree(int inOrder[], int preOrder[]);z
}


