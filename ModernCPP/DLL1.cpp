#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

#define CONTAINING_RECORD(address, type, field) \
    ((type *)((char *)(address) - (unsigned long)(&((type *)0)->field)))
struct Node {
	struct Node* left;
	struct Node* right;
};
struct myNode {
	int val;
	struct Node* list;
};

void Initialize(struct Node*  headNode)
{
	headNode->left = headNode->right = headNode;
}

struct Node*  headNode = NULL;
void InsertNode(struct myNode* p)
{
	struct Node* temp = headNode->right;
	p->list = (struct Node*) malloc(sizeof(struct Node));
	memset(p->list,0, sizeof(struct Node));
	p->list->right= temp;
	p->list->left= headNode;
	headNode->right = p->list;
}

int main_DLL1()
{
	headNode = (struct Node*) malloc(sizeof(struct Node));
	memset(headNode ,0, sizeof(struct Node));
	Initialize(headNode);
	std::cout<<"DLL code\n";

	struct myNode* mn = (struct myNode*) malloc(sizeof(struct myNode));
	mn->val = 1;
	InsertNode(mn);

	/*
	mn = (struct myNode*) malloc(sizeof(struct myNode));
	mn->val = 2;
	InsertNode(mn);

	mn = (struct myNode*) malloc(sizeof(struct myNode));
	mn->val = 3;
	InsertNode(mn);
	*/

	Node* k = headNode->right;
	while(k != headNode) 
	{
		myNode* n = CONTAINING_RECORD(k, myNode, list);
		std::cout<<n->val<<"\n";
		k = k->right;
	}
	return 0;
}
