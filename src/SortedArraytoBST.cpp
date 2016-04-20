/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows
6
/ \
1  10

A BST is said to be balanced ,when it satisifes the following property

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but
right subtree height is 2
(Diff >1)

1
\
3
/ \
10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node* new_node(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
struct node* sortedArrayToBST(int *arr, int first, int last, struct node* root)
{
	if (first > last)
		return NULL;


	int mid = (first + last) / 2; //calculating mid and accordingly traversing left and right par
	root = new_node(arr[mid]);

	root->left = sortedArrayToBST(arr, first, mid - 1, root);//left part

	root->right = sortedArrayToBST(arr, mid + 1, last, root); //right part

	return root;
}
struct node * convert_array_to_bst(int *arr, int len){

	if (arr == NULL || len <= 0)
		return NULL;
	struct node *root = NULL;
	//root = NULL;
	root = sortedArrayToBST(arr, 0, len - 1, root);
	return root;
}

