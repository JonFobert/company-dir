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

    virtual void specialAction() = 0;

public:
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
    void setData(string givenName, int givenSalary, string givenDept)
    {
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
    void setData(string givenName, int givenSalary, string givenDept)
    {
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
}
