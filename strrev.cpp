/*String reversal code*/
/*Changes made in F2 Branch*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#if 0
/*Hello*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node {
	struct Node* next;
	int value;
};

push( struct Node** head , int value)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->value = value;
	
	if(head == NULL)
	{
		*head = temp;
	}
	else
	{
		temp->next = *head;
		*head = temp;
	}
}

//void strrev(struct Node** head , struct Node* headNext)
struct Node*  strrev(struct Node* head , struct Node* headNext)
{
	if (headNext == NULL)
		return NULL;
		
	if (headNext->next == NULL)
	{
		if(head != NULL){
			headNext->next = head;
		}
		head = headNext;
		return head; 
	}
		
	struct Node* temp =  headNext->next;
	headNext->next =  head;
	head = headNext;
	strrev(headNext, temp);
	
}

int main(int argc, char** argv) {
	
	#if 0
	struct Node* head = NULL;
	push( &head, 4);
	push( &head, 3);
	push( &head, 2);
	push( &head, 1);
	
	struct Node* itr = head;
	for(int i = 0; i < 4 ; i++)
	{	
		printf("itr : %d\n",  itr->value);
		itr = itr->next;
	}
	itr = strrev(NULL, head);
	for(int i = 0; i < 4 ; i++)
	{	
		printf("itr : %d\n",  itr->value);
		itr = itr->next;
	}
	getch();
	return 0;
	#endif
	if(0)
         printf("hello\n");
    getch();
    return 0;

	
}
#endif //0


#include <iostream> 
using namespace std; 
  
template <class T> 
T max (T &a, T &b) 
{ 
    return (a > b)? a : b; 
} 
  
template <> 
int max <int> (int &a, int &b) 
{ 
    cout << "Called "; 
    return (a > b)? a : b; 
} 
  
int main () 
{ 
    int a = 10, b = 20; 
    cout << max <int> (a, b); 
    getch();
} 
