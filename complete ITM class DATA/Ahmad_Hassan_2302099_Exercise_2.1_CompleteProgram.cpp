#include <iostream>
#include <conio.h>
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

class Experience 
{
	public:
	    string jobTitle;
	    string companyName;
	    string startDate;
	    string endDate;
	
	    Experience(string title, string company, string start, string end)
	        : jobTitle(title), companyName(company), startDate(start), endDate(end) {}
};

int main() 

{
    SinglyList experienceList;

    Experience exp1("Software Engineer", "ITM", "2018-01-01", "2020-02-15");
    Experience exp2("Data Analyst", "I2C", "2019-04-10", "2021-07-20");
    Experience exp3("Project Manager", "ZONG", "2020-08-30", "2022-12-05");

    experienceList.insert(&exp1, 0);
    experienceList.insert(&exp2, 1);
    experienceList.insert(&exp3, 2);

    for (int i = 0; i < 3; ++i) 
	
	{
        Experience *exp = reinterpret_cast<Experience*>(experienceList.read(i));
        
		if (exp != NULL) 
		{
            cout << "Job Title: " << exp->jobTitle << endl;
            cout << "Company Name: " << exp->companyName << endl;
            cout << "Start Date: " << exp->startDate << endl;
            cout << "End Date: " << exp->endDate << endl;
            cout << "-----------------------" << endl;
        }
    }

    getch();
    return 0;
}

