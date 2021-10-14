#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*MNOPQ*/
/*
using namespace std;

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};*/
/*HURRRRAYYYY*/
using namespace std;
/*HURRRRAYYYY*/
struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};
/*HURRRRAYYYY*/
struct Node1 {
	struct Node1* next;
	int value;
};
/*HURRRRAYYYY*/
void BSTInsert(struct Node** root, int i)
{
	if (*root == NULL)
	{
		/*HURRRRAYYYY*/
		(*root) = (struct Node*) malloc(sizeof(struct Node));
		(*root)->val = i;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
		if (i < (*root)->val)
		{
			BSTInsert(&((*root)->left), i);
		}
		else if (i > (*root)->val)
		{
			BSTInsert(&((*root)->right), i);
		}
		/*HURRRRAYYYY*/
		
}
/*HURRRRAYYYY*/
/*HURRRRAYYYY*/
/*HURRRRAYYYY*//*HURRRRAYYYY*/

adadsssssssssssssssssssssssss
struct Node1* head = NULL;
void push(struct Node1** head, int value)
adadsssssssssssssssssssssssss
{
	struct Node1* temp = (struct Node1*) malloc(sizeof(struct Node1));
	temp->value = value;adadsssssssssssssssssssssssss

	if (head == NULL)adadsssssssssssssssssssssssss
	{
		*head = temp;
	}
	else
	{
		temp->next = *head;
		*head = temp;
	}
}

void BST_inorderAndStore(struct Node* root)
{
	if (root->left != NULL)
		BST_inorderAndStore(root->left);

	printf("%d\n", root->val);
	push(&head, root->val);

	if (root->right != NULL)
		BST_inorderAndStore(root->right);

}


int main()
{
	struct Node* root = NULL;

	BSTInsert(&root, 13);
	BSTInsert(&root, 3);
	BSTInsert(&root, 14);
	BSTInsert(&root, 1);
	BSTInsert(&root, 4);
	BSTInsert(&root, 18);
	BSTInsert(&root, 2);
	BSTInsert(&root, 12);
	BSTInsert(&root, 10);
	BSTInsert(&root, 5);
	BSTInsert(&root, 11);
	BSTInsert(&root, 8);
	BSTInsert(&root, 7);
	BSTInsert(&root, 9);
	BSTInsert(&root, 6);
	
	BST_inorderAndStore(root);

	struct Node1* temp = head;
	for (;temp != NULL; temp = temp->next)
	{

		if (temp->next != NULL && temp->value < temp->next->value)
			return 1;


	}
	printf("%s\n", "Binary Search Tree!");
}


