/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void quicksort(int *x, int first, int last){
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (x[i] <= x[pivot] && i<last)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort(x, first, j - 1);
		quicksort(x, j + 1, last);

	}
}
void inorder_traversal1(struct node *root, int *arr, int *index){
	if (root != NULL)
	{
		inorder_traversal1(root->left, arr, index);
		*index = *index + 1;
		arr[*index] = root->data;
		inorder_traversal1(root->right, arr, index);
	}
}
void setTreedata(struct node* root, int *arr, int* index1){
	if (root == NULL)return;
	setTreedata(root->left, arr, index1);
	root->data = arr[*index1];
	*index1 = *index1 + 1;
	setTreedata(root->right, arr, index1);
}
void fix_bst(struct node *root){

	if (root != NULL)
	{
		int index = -1, i = 0;
		int *arr = (int *)malloc(10 * sizeof(int));
		inorder_traversal1(root, arr, &index);
		quicksort(arr, 0, sizeof(arr) - 1);
		//int size = sizeof(arr);
		int index1 = 0;
		setTreedata(root, arr,&index1);

		//display(arr, sizeof(arr));
	}
}
