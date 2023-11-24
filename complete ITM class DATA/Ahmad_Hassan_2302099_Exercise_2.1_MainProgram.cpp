#include <iostream>
#include <conio.h>
#include <SinglyList.h>

using namespace std;

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

