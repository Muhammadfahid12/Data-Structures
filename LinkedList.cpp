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
    Node* head = NULL;
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



    //inserting at the beginning of linked list;
    void insert(int data)
    {

       Node* temp = new Node(data);
        temp->next =  head;
        head = temp;
        listSize+=1;
    }

    //insertion at the end of linked list

    void endInsert(int data)
    {
        Node* last = new Node(data);

        while(head != NULL)
        {
            
        }


    }
    
    //find element at specific index;
    int getElement(int index)
    {

        Node * temp = head ;
        for(int i = 0 ; i < index ;i++ )
        {
            temp = temp->next;
        }
        return temp->data;
    }


};

int main()
{

    singlyList lists(8) ;

    lists.insert(11);
     lists.insert(12);

    // cout << "Size: " <<list.getSize();

    int x = lists.getSize();
    cout << "Size: " << x <<endl;
    for ( int i = 0 ; i < x ;i++)
    {
    cout << lists.getElement(i) << endl;
    }
    
    return 0;
}