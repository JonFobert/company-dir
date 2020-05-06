#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct employeeData
{
    string name;
    int salary;
    string dept;
} employeeData;

class Employee
{
protected:
    string name;
    int salary;
    string dept;

public:
    virtual void specialAction() = 0;
    virtual bool askToAdd() = 0;
    virtual employeeData getData() = 0;
    virtual void setData() = 0;

    Employee()
    {
        /*
        name = "noName";
        salary = 1;
        dept = "noDept";
        */
    }
    Employee(string givenName, int givenSalary, string givenDept)
    {
        name = givenName;
        salary = givenSalary;
        dept = givenDept;
    }
};

/*************************************
 * Class for Individual Contributers *
 *************************************/

class IndivContributer : public Employee
{
public:
    void setData()
    {
        cout << "Name?";
        cin.ignore();
        string givenName;
        cin >> givenName;
        cout << "Salary?";
        cin.ignore();
        int givenSalary;
        cin >> givenSalary;
        cout << "Department?";
        cin.ignore();
        string givenDept;
        cin >> givenDept;

        name = givenName;
        salary = givenSalary;
        dept = givenDept;
    }

    employeeData getData()
    {
        employeeData returnedEmployeeData;
        returnedEmployeeData.name = name;
        returnedEmployeeData.salary = salary;
        returnedEmployeeData.dept = dept;
        return returnedEmployeeData;
    }

    void specialAction()
    {
        cout << "Sell Stock Now!";
    }

    bool askToAdd()
    {
        cout << "Would  you like to add an individual contributer?";
        bool response;
        cin >> response;
        return response;
    }

    IndivContributer()
    {
        /*
        name = "noName";
        salary = 1;
        dept = "noDept";
        */
    }
    IndivContributer(string givenName, int givenSalary, string givenDept)
    {
        name = givenName;
        salary = givenSalary;
        dept = givenDept;
    }
};

/*************************************
 *        Class for Executives       *
 *************************************/

class Executive : public Employee
{
public:
    void setData()
    {
        cout << "Name?";
        cin.ignore();
        string givenName;
        cin >> givenName;
        cout << "Salary?";
        cin.ignore();
        int givenSalary;
        cin >> givenSalary;
        cout << "Department?";
        cin.ignore();
        string givenDept;
        cin >> givenDept;

        name = givenName;
        salary = givenSalary;
        dept = givenDept;
    }

    employeeData getData()
    {
        employeeData returnedEmployeeData;
        returnedEmployeeData.name = name;
        returnedEmployeeData.salary = salary;
        returnedEmployeeData.dept = dept;
        return returnedEmployeeData;
    }

    void specialAction()
    {
        cout << "All hands!";
    }

    bool askToAdd()
    {
        cout << "Would  you like to add an executive?";
        bool response;
        cin >> response;
        return response;
    }

    Executive()
    {
        /*
        name = "noName";
        salary = 1;
        dept = "noDept";
        */
    }
    Executive(string givenName, int givenSalary, string givenDept)
    {
        name = givenName;
        salary = givenSalary;
        dept = givenDept;
    }
};

int main()
{
    //https://stackoverflow.com/questions/33123371/how-to-create-array-of-an-abstract-class-in-c/33123456
    Employee *employees[50];
    int employeesCounter = 0;

    bool moreEmployeesToAdd = true;

    while (moreEmployeesToAdd)
    {
        int response;
        cout << "Welcome to the Company Directory!\nWhat would you like to do?\n0 - Quit\n1 - Display list of employees\n2 - Add an Employee\n";
        cin >> response;
        if (response == 0)
        {
            moreEmployeesToAdd = false;
        }
        if (response == 1)
        {
            employeeData employeeElementData = employees[0]->getData();
            cout << employeeElementData.name;
            cout << employeeElementData.salary;
            cout << employeeElementData.dept;
            cout << "\n\n";
            //}
        }
        if (response == 2)
        {
            cout << "Would you like to add an individual Contributer?\n0 - No\n1 - Yes\n";
            cin.ignore();
            cin >> response;
            if (response)
            {
                IndivContributer newIndivContr;
                Employee *hiredEmployee = &newIndivContr;
                hiredEmployee->setData();
                hiredEmployee->getData();
                employees[employeesCounter] = hiredEmployee;
                employeesCounter++;
            }
            else
            {
                cout << "Would you like to add an Executive?\n0 - No\n1 - Yes\n";
                cin.ignore();
                cin >> response;
                if (response)
                {
                    Executive newExec;
                    Employee *hiredEmployee = &newExec;
                    hiredEmployee->setData();
                    hiredEmployee->getData();
                    employees[employeesCounter] = hiredEmployee;
                    employeesCounter++;
                }
                else
                {
                    moreEmployeesToAdd = false;
                }
            }
        }
    }
}
