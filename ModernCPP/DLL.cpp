#include <stdio.h>
#include <iostream>
#include<memory>
#include<mutex>
#include<thread>
#include <chrono>
#include <cstring>

struct Node {
	struct Node* left;
	struct Node* right;
	int val;
};
struct myNode {
	int val;
	struct Node* node;
};
void Initialize(struct Node*  headNode)
{
	headNode->left = headNode->right = headNode;
}
struct Node*  headNode = NULL;
//void InsertNode(struct myNode* p)
void InsertNode(struct Node* p)
{
	p->node->right = NULL;
	p->node->left = NULL;
	struct Node* temp = headNode->right;
	p->node->right= temp;
	p->node->left= headNode;
	headNode->node->right= p;
}

int main_DLL()
{
	headNode = (struct Node*) malloc(sizeof(struct Node));
	memset(headNode ,0, sizeof(struct Node));
	Initialize(headNode);
	std::cout<<"DLL code\n";

	struct myNode* mn = (struct myNode*) malloc(sizeof(struct myNode));
	mn->val = 1;
	InsertNode(mn);

	mn = (struct myNode*) malloc(sizeof(struct myNode));
	mn->val = 2;
	InsertNode(mn);

	mn = (struct myNode*) malloc(sizeof(struct myNode));
	mn->val = 3;
	InsertNode(mn);

	Node* k = headNode->right;
	while(k != headNode) 
	{
		std::cout<<k->val<<"\n";
		k = k->right;
	}
	return 0;
}
