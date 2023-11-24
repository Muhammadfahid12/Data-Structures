#include <iostream>
using namespace std;

class DoublyList
{
    class Node
    {
    public:
        void *data;
        Node *next;
        Node *prev;

        Node()
        {
            data = NULL;
            next = NULL;
            prev = NULL;
        }

        Node(void *data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    int listSize = 0;

   public:
            DoublyList()
            {
             head = NULL;
             tail = NULL;
             listSize = 0;
            } 

            DoublyList(void* data)
            {
                
            }




};