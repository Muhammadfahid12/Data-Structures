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

    Node *head;
    Node *tail;
    int listSize = 0;

    Node *getNode(int index)
    {
        Node *n = NULL;

        if (index >= 0)
        {
            n = this->head;
            for (int i = 0; i < index; i++)
            {
                n = n->next;
            }
        }
        else
        {
            n = this->tail;
            for (int i = -1; i > index; i--)
            {
                n = n->prev;
            }
        }
        return n;
    }

public:
    DoublyList()
    {
        head = NULL;
        tail = NULL;
        listSize = 0;
    }

    DoublyList(void *data)
    {
        this->head = new Node(data);
        this->tail = this->head;
        this->listSize = 1;
    }

    // getting an element through index;

    void *read(int index = -1)
    {
        Node *Slider = getNode(index);
        return Slider->data;
    }

    int size()
    {
        return listSize;
    }

    // insertion
    void insert(int index, void *data)
    {
        Node *newNode = NULL;
        // if insert in between linked list

        if (index > 0)
        {
            newNode = new Node(data);
            Node *slider = getNode(index);

          
            //in line 96 and 99 ,newNode have made connection with other tow neighbours pointers

            newNode->next = slider;
            newNode->prev = slider->prev;


            //now we have to linked newNode to previous indexed node and next indexed node .
            newNode->next->prev = newNode;
            newNode->prev->next = newNode;

            //till line 104,our newNode is connected

        }

        
    }
};