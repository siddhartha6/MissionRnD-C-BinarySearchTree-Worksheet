/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
2
/ \
,   1   3
\
14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
2
/ \
1   3
\
14
/ \
9   20
/      \
6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>
#define default 2145678
struct node{
	struct node * left;
	int data;
	struct node *right;
};


int getMin(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}
int closest_leaf_distance(struct node *root)
{
	if (root == NULL)
		return default;
	if (root->left == NULL && root->right == NULL)
		return 0;
	return 1 + getMin(closest_leaf_distance(root->left), closest_leaf_distance(root->right));
}

int closest_node(struct node *root, char k, struct node *a[], int index)
{
	if (root == NULL)
		return default;
	if (root->data == k)
	{
		int res = closest_leaf_distance(root);
		for (int i = index - 1; i >= 0; i--)
			res = getMin(res, index - i + closest_leaf_distance(a[i]));
		return res;
	}
	a[index] = root;
	return getMin(closest_node(root->left, k, a, index + 1),
		closest_node(root->right, k, a, index + 1));

}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	char k = temp->data;
	struct node *a[20];
	int res = closest_node(root, k,a,0);
	return res;
}
