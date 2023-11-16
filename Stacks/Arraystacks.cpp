#include <iostream>
using namespace std;

class StaticStack
{

    int MaxSize;
    int top = -1;
    void **stackArray;

public:
    StaticStack()
    {
    }

    StaticStack(int size)
    {
        this->MaxSize = size;
        // stackSize[this->MaxSize];
        stackArray = new void *[MaxSize];
    }

    void push(void *x)
    {
        stackArray[++top] = x;
    }

    void pop()
    {
        --top;
    }

    void display()
    {
        for (int i = 0; i < MaxSize; i++)
        {
            cout << stackArray[i] << endl;
        }
    }
};

int main()
{
    StaticStack obj(1);
    int x = 1;
    obj.push(&x);
    obj.pop();
    obj.display() ;
    return 0;
}
