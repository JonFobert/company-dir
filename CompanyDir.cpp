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
    bool moreEmployeesToAdd = true;

    bool response;
    cout << "Welcome to the Company Directory!\nWhat would you like to do?\n0 - Display list of employees\n1 - Add an Employee\n";
    cin >> response;
    while (moreEmployeesToAdd)
    {
        if (response)
        {
            cout << "Would you like to add an individual Contributer?\n0 - No\n1 - Yes\n";
            cin.ignore();
            cin >> response;
            if (response)
            {
                Employee *hiredEmployee = new IndivContributer;
                hiredEmployee->setData();
                hiredEmployee->getData();
            }
            else
            {
                cout << "Would you like to add an Executive?\n0 - No\n1 - Yes\n";
                cin.ignore();
                cin >> response;
                if (response)
                {
                    Employee *hiredEmployee = new Executive;
                    hiredEmployee->setData();
                    hiredEmployee->getData();
                }
                else
                {
                    moreEmployeesToAdd = false;
                }
            }
        }
    }
    /*
    IndivContributer moe;
    moe.setData("moe", 43, "writing");
    employeeData moesData = moe.getData();
    cout << moesData.name << "\n"
         << moesData.salary << "\n"
         << moesData.dept << "\n";

    Executive carl;
    carl.setData("carl", 430, "directing");
    employeeData carlsData = carl.getData();
    cout << carlsData.name << "\n"
         << carlsData.salary << "\n"
         << carlsData.dept << "\n";
    */
}
