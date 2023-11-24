#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

// Holding data in the RAM in an organized structured fashion is an example of data struncture.
// Stack is a linear (Only one item after the other) data structure.
// Store word is used for HDD. 
// Non-Linear --- > Trees and Branches
// There are two ways to implement stacks --- > Arrays, List



class StaticStack
{
		int max_size;
		int topE = -1;
		void **arr;							// Here, arr is a pointer that can hold the address of another pointer of data type void.
											// We call such a pointer, double pointer or pointer to a pointer. 
		
	public:
		
		StaticStack(int size)
		{
			max_size = size;
			arr = new void*[max_size];	   // Here, arr is a pointer to a void pointer, representing an array that holds void pointers. 
		}
		
		void push(void* val)
		{
			topE++;
			if(topE < max_size)
			{
				arr[topE] = val;		  // Here, arr points to the address of pointer representing array. So, word arr give us the address of
			}							  // pointer which is pointing to actualy array of pointers. Now square brackets '[]' work here as dereferencing
										  // operator and allows us to update or fetch the values at a given index of the array.
			else
			cout <<"\n ERROR: Stack Overflow." << endl;
		}
		
		void pop()
		{
			topE--;
		}
		
		void* top()
		{
			return arr[topE];
		}
		
			
};

int main()

{
	int size;
	cout << "\nEnter the size of the stack: ";
	cin >> size;
		
	StaticStack s1(size);
	int val1 = 5;
	int val2 = 6;
	
	s1.push(&val1);
	s1.push(&val2);
	
	cout << *(int*)s1.top() << endl;
	
	getch();
	return 0;
}

