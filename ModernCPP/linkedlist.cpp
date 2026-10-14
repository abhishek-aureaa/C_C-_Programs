#include <iostream>
#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct Node {
	int val;
	struct Node* next;
};
struct Node* head = NULL;

void PUSH(int val)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	memset(temp, 0, sizeof(struct Node));
	temp->val = val;
	temp->next = NULL;
	temp->next = head;
	head = temp;
}

struct Node* reverse()
{
	struct Node* prev = NULL;
	struct Node* current = head;
	while(current)
	{
		struct Node* temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	return prev;
}

bool Empty()
{
	if(head == NULL)
		return true;

	return false;
}

void InsertFirstNode(int val)
{
	PUSH(val);
}
void InsertAtHead(int val)
{
	PUSH(val);
}
void InsertAtTail(int val)
{
	struct Node* t = NULL;
	struct Node* temp = head;
	struct Node* current = head;
	while(current)
	{
		temp = current;
		current = current->next;
	}
	t = (struct Node*) malloc(sizeof(struct Node));
	memset(t, 0, sizeof(struct Node));
	t->val = val;
	t->next = NULL;
	temp->next = t;
}

int main_linkedlist()
{
	if(Empty())
		std::cout<<"Empty\n";
	InsertFirstNode(5);
	if(Empty())
		std::cout<<"Empty\n";
	else 
		std::cout<<"Not Empty\n";
	PUSH(1);
	PUSH(2);
	PUSH(3);
	PUSH(4);
	InsertAtTail(7);
	struct Node* temp = reverse();
	while(temp)
	{
		std::cout<<temp->val;
		temp = temp->next;
	}
	std::cout<<"\n";
    return 0;
}
