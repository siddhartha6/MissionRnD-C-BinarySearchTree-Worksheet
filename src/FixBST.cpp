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

void quicksort(int *array, int first, int last){
	
	int pivot=0, index1=0, temp=0, index2=0;

	if (first<last){
		pivot = first;
		index1 = first;
		index2 = last;

		while (index1<index2){
			while (array[index1] <= array[pivot] && index1<last)
				index1++;
			while (array[index2]>array[pivot])
				index2--;
			if (index1<index2){
				temp = array[index1];
				array[index1] = array[index2];
				array[index2] = temp;
			}
		}

		temp = array[pivot];
		array[pivot] = array[index2];
		array[index2] = temp;
		quicksort(array, first, index2 - 1);
		quicksort(array, index2 + 1, last);

	}
}
int tree_size(struct node* root)
{
	if (root == NULL)
		return 0;
	else
		return(tree_size(root->left) + tree_size(root->right) + 1);
}
void inorder_array(struct node *root, int *elements, int *index){
	if (root != NULL)
	{
		inorder_array(root->left, elements, index);
		*index = *index + 1;
		elements[*index] = root->data;
		inorder_array(root->right, elements, index);
	}
}
void inorder_tree(struct node* root, int *elements, int* index){
	if (root != NULL)
	{
		inorder_tree(root->left, elements, index);
		*index = *index + 1;
		root->data = elements[*index];
		inorder_tree(root->right, elements, index);
	}
}

void fix_bst(struct node *root){

	if (root != NULL)
	{
		int index = -1, i = 0;
		int no_elements = tree_size(root);
		int *elements = (int *)malloc(no_elements* sizeof(int));
		inorder_array(root, elements, &index);
		quicksort(elements, 0, no_elements- 1);
		index = -1;
		inorder_tree(root,elements,&index);
	}

}
