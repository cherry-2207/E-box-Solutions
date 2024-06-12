//Complete Binary Tree ---  check if it is BST
#include<stdio.h>
#include<stdlib.h>

int * createCompleteBinaryTree(int n);
void printCompleteBinaryTree(int * tree, int n);
int isBST(int * tree, int n);

int main()
{
	int n, * tree;
	printf("Enter the number of elements in the tree\n");
	scanf("%d",&n);
	tree = createCompleteBinaryTree(n);
	printCompleteBinaryTree(tree,n);
	if(isBST(tree,n))
		printf("The tree is a BST\n");
	else
		printf("The tree is not a BST\n");
	return 0;
}

int * createCompleteBinaryTree(int n)
{
	int i;
	int * tree = (int *) malloc((n)*sizeof(int));
	printf("Enter the elements in the tree\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(tree+i));
	}
	return tree;
}


void printCompleteBinaryTree(int * tree, int n)
{
	int i;
	printf("The elements in the tree in level order are");
	for(i=0;i<n;i++)
		printf(" %d",*(tree+i));
	printf("\n");
}

int isBST(int * tree, int n)
{
	 // Check if the given tree is a BST
    for (int i = 0; i < n; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // If left child exists and it's greater than the parent, not a BST
        if (leftChild < n && tree[leftChild] > tree[i])
            return 0;

        // If right child exists and it's less than or equal to the parent, not a BST
        if (rightChild < n && tree[rightChild] <= tree[i])
            return 0;
    }
    // If all nodes satisfy BST property
    return 1;
}




