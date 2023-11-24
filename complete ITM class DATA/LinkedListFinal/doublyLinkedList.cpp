// Doubly Linked List



#include <iostream>
#include <conio.h>

using namespace std;

class List

{
	private:
		
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
		Node *tail = NULL;
		int size = 0;
	
	public:
		
		List()
		
		{
			this->size = 0;
			this->head = NULL;
			this->tail = NULL;
		}
	
		List(void *data)
		{
			this->head = new Node(data);
			this->tail = this->head;
			this->size = 1;
		}
		
		int listSize()
		{
			return this->size;
		}
			
		
		void* read(int index = -1)
		
		{
			Node *slider = NULL;
			
			if(index >= 0)
			
			{
				slider = head;
				
				for(int i = 0; i < index; i++)
				slider = slider->next;
				
				return slider->data;
				
			}
			
			else
			
			{
				slider = tail;
				
				for(int i = -1; i > index ; i--)
				slider = slider->prev;
				
				return slider->data;
				
			}
			
		}
		
		
		void insert (int index = -1, void* data = NULL) // start. middle, end
		
		{
			if(index == 0)
			
			{
				Node *tmp  = head;
				this->head = new Node(data);
				this->head->next = tmp;
				tmp->prev = this->head;
				size += 1; 
				
			}
			
			else if(index == -1 || index == (this->size-1))
			
			{
				Node *tmp  = tail;
				this->tail = new Node(data);
				this->tail->prev = tmp;
				tmp->next = this->tail;
				size += 1;
			}
			
			else
			
			{	
				Node *slider = NULL;
				Node *tmp = new Node(data);
				
				if(index >= 0) // traverse from head ...
				{
					slider =head;
					
					for(int i = 0; i < index - 1; i++)
						slider = slider->next;
					
					tmp->next = slider->next;
					tmp->prev = slider;
					slider->next->prev = tmp;
					slider->next = tmp;
											
					this->size += 1;
					
				}
				
				else			// traverse from tail ...
				{
					slider = tail;
					
					 for(int i = -1 ; i > index - 1; i--) // for (int i = index ; i < -1; i++)
						slider = slider->prev;
										
					tmp->prev = slider->prev;
					tmp->next = slider;
					slider->prev->next = tmp;
					slider->prev = tmp;
					
					this->size += 1;
				}
				
			}
			
		}
		
		
		void remove (int index = -1)
		{
			Node* slider = NULL;
		
			if (index == 0)
			{
				Node* tmp = this->head;
				this->head = tmp->next;
				this->head->prev = NULL;
				
				delete tmp;
				
				this->size -= 1;
			}
			
			else if (index == -1 || index == (this->size-1))
			{
				Node* tmp = this->tail;
				this->tail = tmp->prev;
				this->tail->next = NULL;
				
				delete tmp;
	
				this->size -= 1;
			}
			
			else 
			{
				if(index >= 0) // traverse from head ...
				{
					slider = head;
					
					for(int i = 0; i < index-1; i++) //
						slider = slider->next;
									
					slider->prev->next = slider->next;
					slider->next->prev = slider->prev;
					
					delete slider;
					
					this->size -= 1;
					
				}
				
				else			// traverse from tail ...
				{
					
					slider = tail;
					
					 for(int i = -1 ; i > index ; i--) // for (int i = index ; i < -1; i++)
						slider = slider->prev;
				
					
					slider->prev->next = slider->next;
					slider->next->prev = slider->prev;
					
					delete slider;
					
					this->size -= 1;
				}
			}
		}
		
		void append(void *data)
		
		{
				Node *tmp  = tail;
				this->tail = new Node(data);
				this->tail->prev = tmp;
				tmp->next = this->tail;
				size += 1;
		}
		
		bool isEmpty()
		{
			if (size == 0)
			return true;
			
			else
			return false;
		}
	
};



int main()

{	
	
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	int num4 = 40;
	int num5 = 50;
	
	List lis(&num1);
	lis.insert(-1, &num2);
	lis.insert(-1, &num3);
	lis.insert(0, &num4);
	lis.insert(2, &num5);
	
//	cout << lis.read(0) << endl << *(int*)lis.read(0) << endl << endl;


	cout << "\nTraverse from head." << endl;
	cout << num1 << endl << &num1 << endl << lis.read(0) << endl << *(int*)lis.read(0) << endl << endl; 
	
	cout << num2 << endl << &num2 << endl << lis.read(1) << endl << *(int*)lis.read(1) << endl << endl; 
	
	cout << num3 << endl << &num3 << endl << lis.read(2) << endl << *(int*)lis.read(2) << endl << endl; 
	cout << num4 << endl << &num4 << endl << lis.read(0) << endl << *(int*)lis.read(0) << endl << endl; 
	cout << num5 << endl << &num5 << endl << lis.read(2) << endl << *(int*)lis.read(2) << endl << endl; 
	cout << lis.read(3) << endl << *(int*)lis.read(3) << endl << endl;
	cout << lis.read(4) << endl << *(int*)lis.read(4) << endl << endl;



	cout << "\nTraverse from tail." << endl;
	cout << lis.read(-1) << endl << *(int*)lis.read(-1) << endl;
	cout << lis.read(-2) << endl << *(int*)lis.read(-2) << endl;
	
	getch();
	return 0;	
}

