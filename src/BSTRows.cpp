/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void bst_row(struct node* root, int level, int* result,int *res_index){
	if (root == NULL)
		return;
	if (level == 1){
		*res_index = *res_index + 1;
		result[*res_index] = root->data;
	}
	else if (level > 1){
		bst_row(root->right, level - 1, result,res_index);
		bst_row(root->left, level - 1, result,res_index);
	}
}
int tree_height(struct node *root){

	if (root == NULL)
		return 0;

	int left_part = tree_height(root->left);
	int right_part = tree_height(root->right);

	if (left_part > right_part)
		return(left_part + 1);
	else
		return(right_part + 1);
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		 return NULL;
	
	int *result = (int*)malloc(10*sizeof(int));
	int height = tree_height(root);
	int res_index = -1,level=1;

	while (level <= height){
		bst_row(root,level,result,&res_index);
		level++;
	}
	return result;

}





