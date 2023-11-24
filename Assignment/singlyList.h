#ifndef singlyList_h // include guard
#define singlyList_h


#include <iostream>
using namespace std;

class SinglyList 

{
    class Node 
	{
	public:
 
 	    void* data;
        Node* next;   	
 
        Node() 
		
		{
            data = NULL;
            next = NULL;
        }
    };

    Node* head;

public:
	
    SinglyList() 
	{
        head = NULL;
    }

    void* read(int index) 
	
	{
        Node* current = head;
        int count = 0;

        while (current != NULL) 
		
		{
            
			if (count == index) 
			
			{
                return current->data; 
            }
            
            count++;
            current = current->next;
        }

        return NULL; 
    }

    void insert(void* pointer, int index = 0) 
	
	{
        Node* new_node = new Node;
        new_node->data = pointer;

        if (index == 0) 
		
		{
            new_node->next = head;
            head = new_node;
        } 
		
		else 
		
		{
            Node* current = head;
            int count = 0;

            while (current != NULL && count < index - 1) 
			
			{
                current = current->next;
                count++;
            }

            if (current != NULL) 
			
			{
                new_node->next = current->next;
                current->next = new_node;
            } 
			
			else 
			
			{
                Node* last = head;
                
				while (last->next != NULL) 
				{
                    last = last->next;
                }
            
			    last->next = new_node;
                new_node->next = NULL;
            }
        }
    }
};


#endif