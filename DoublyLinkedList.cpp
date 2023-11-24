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
            return n;
        }
        else
        {
            n = this->tail;
            for (int i = -1; i > index; i--)
            {
                n = n->prev;
            }
        }
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
        if (index >= 0)
        {
            Node *n = this->head;

            for (int i = 0; i < index; i++)
            {
                n = n->next;
            }
        }
    }
};