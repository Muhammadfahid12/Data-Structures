#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;


class Stack
{
	
	class Node
		
		{
			public:
				
				Node *next;
				void *data;
				Node *prev;
				
				Node()
				
				{
					this->next = NULL;
					this->data = NULL;
					this->prev = NULL;
				}
				
				Node(void *data)
				{
					this->data = data;
					this->next = NULL;
					this->prev = NULL;
				}
		};
	
		Node *head = NULL;
					
	public:
		
		Stack()
		{
			this->head = NULL;
		}
		
		
		Stack(void *data)
		{
			this->head = new Node(data);
		}
		
		void push(void* val)
		{
			
			if((this->head) == NULL) 
			{
				this->head = new Node(val);
			}
			
			else
			{
			
				Node *tmp  = head;
				this->head = new Node(val);
				this->head->next = tmp;
				tmp->prev = this->head;
			}
		}
		
		void pop()
		{
			Node* tmp = this->head;
			this->head = tmp->next;
			this->head->prev = NULL;
				
			delete tmp;
		}
		
		void* top()
		{
			return this->head->data;
		}
		
			
};

int main()

{
	
	int val1 = 5;
	int val2 = 6;
	
	Stack s1(&val1);
	
	s1.push(&val2);
	
	cout << *(int*)s1.top() << endl;
	
	getch();
	return 0;
}

