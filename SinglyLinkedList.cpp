#include <iostream>
using namespace std;

class singlyList
{

private:
    class Node
    {

    public:
        int data;
        Node *next;

        Node()
        {
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
    };
    // creating a new node
    Node *head = NULL;
    int listSize = 1;

public:
    singlyList()
    {
    }

    singlyList(int data)
    {
        head = new Node(data);
        listSize = 1;
    }

    int getSize()
    {
        return listSize;
    }

    // inserting at the beginning of linked list;
    void insert(int data)
    {

        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        listSize += 1;
    }

    // insertion at the end of linked list

    void endInsert(int data)
    {
        Node *last = new Node(data);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = last;
            last->next = NULL;
            listSize += 1;
        }
    }

    // inserting at a particular index

    void customInsert(int data, int index)
    {
         if (index < 0 || index > listSize)
        {
            cout << "Invalid index " << endl;
            return;
        }
        
        Node *temp = head;
        Node *previous = head;
        Node *newElement = new Node(data);

        for (int i = 0; i < index; i++)
        {
            temp = temp->next; // it will lead us to the desired index
        }
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->next; // one element before the desired index
        }

        newElement->next = temp; // new element will point to node at the given index present already;
        previous->next = newElement;
        listSize += 1;
    }

    // find element at specific index;
    int getElement(int index)
    {
        if (index < 0 || index > listSize)
        {
            cout << "Invalid index " << endl;
            return 1;
        }

        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    // remove element at the given index;

    void remove(int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

int main()
{

    singlyList lists(8);

    lists.insert(11);
    lists.insert(12);
    lists.endInsert(77);
    lists.endInsert(79);
    lists.customInsert(101, 1);
    lists.customInsert(404, 3);

    int x = lists.getSize();
    cout << "Size: " << x << endl;
    for (int i = 0; i < x; i++)
    {
        cout << lists.getElement(i) << endl;
    }

    return 0;
}