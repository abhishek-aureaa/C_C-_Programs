#include <stdio.h>
#include <iostream>
#include<memory>
#include<mutex>
#include<thread>
#include <chrono>
#include <cstring>

struct Node {
	struct Node* next;
	int val;
};

static struct Node * head = NULL;
void PUSH(struct Node* p)
{
	p->next = head;
	head = p;
}

void InsertAtTail(struct Node* p)
{
	if(head == NULL)
	{
		PUSH(p);
		return;
	}
	struct Node* temp = head;
	struct Node* last = head;
	while(temp)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = p;
}

void DeleteFirstNode()
{
	if(head == NULL)
		return;

	struct Node* temp = head;
	head = head->next;
	free(temp);
}
void traverse()
{
	struct Node* temp = head;
	while(temp)
	{
		std::cout<<temp->val;
		temp = temp->next;
	}
}
void DeleteLastNode()
{
	if(head == NULL)
		return;

	if(head->next == NULL)
	{
		struct Node* temp = head;	
		delete(temp);
		return;
	}
	struct Node* temp = head;
	struct Node* last = head;
	while(temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
        delete(temp);	
}
void SearchExistingNode(struct Node* p)
{
	struct Node* temp = head;
	while(temp)
	{
	 	if(temp == p)
		{
			std::cout<<"Found node\n";
			return;
		}
		temp = temp->next;
	}
}
void SearchNonExistingNode(struct Node* p)
{
	struct Node* temp = head;
	while(temp)
	{
	 	if(temp == p)
		{
			return;
		}
		temp = temp->next;
	}
	std::cout<<"Not Found node\n";
}

int main_LL()
{
	struct Node* t = (struct Node*) malloc(sizeof(struct Node));
	memset(t,0, sizeof(struct Node));
	t->next = NULL;
	t->val = 3;
	InsertAtTail(t);
	traverse();
	return 0;
	PUSH(t);
	t = (struct Node*) malloc(sizeof(struct Node));
	memset(t,0, sizeof(struct Node));
	t->next = NULL;
	t->val = 2;
	PUSH(t);
	struct Node* t1 = t;
	t = (struct Node*) malloc(sizeof(struct Node));
	memset(t,0, sizeof(struct Node));
	t->next = NULL;
	t->val = 1;
	PUSH(t);
	t = (struct Node*) malloc(sizeof(struct Node));
	memset(t,0, sizeof(struct Node));
	t->next = NULL;
	t->val = 4;
	InsertAtTail(t);
	t = (struct Node*) malloc(sizeof(struct Node));
	memset(t,0, sizeof(struct Node));
	t->next = NULL;
	t->val = 5;
	struct Node* t2 = t;
	//InsertAtTail(t);
	//DeleteFirstNode();
	//DeleteLastNode();
	SearchExistingNode(t1);
	SearchNonExistingNode(t2);
	traverse();
	return 0;
}
