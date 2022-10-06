#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee {
    
protected:
    string name;
    string ID;
    char empClass;
    int salary;
    
public:
    Employee(); // Default constructor
    Employee(istream&); // constructor to populate objects from file or user input
    Employee(string, string, char, int); // Explicit-value constructor
    void setSalary(int); // mutator method to set or change salary
    int getSalary() const; // constant accessor method to get salary of employee
    void setClass(char); // setter function of Employee class
    string getName() const; //constant accessor method to get name of employee
    virtual void read(istream&); // virtual utility function for overloading input operator
    virtual void display(ostream&); // virtual utility function for overloading output operator
    virtual int calculateSalary(int); // virtual function which calculates monthly salary of employee
    
};

class Chef : public Employee {
    
    string cuisine;
    
public:
    Chef(istream&); // constructor to populate objects from file or user input
    Chef(string, string, string); // explicit-value constructor
    void setCuisine(string); // setter method for the data member cuisine
    string getCuisine() const; // getter method for the data member cuisine
    void read(istream&); // utility function for overloading input operator
    void display(ostream&); // utility function for overloading input operator
    int calculateSalary(int); // function which calculates monthly salary of chef
    
};

class Waiter : public Employee {
    
    int expYears;
    int tips;
    
public:
    Waiter(istream&); // constructor to construct objects based on information from the user or file
    Waiter(string, string, int, int); // explicit-value constructor
    void setExpYears(int); // setter of the data member expYears
    int getExpYears() const; // getter of the data member expYears
    void setTips(int); // setter of the data member tips
    int getTips() const; // getter of the data member expYears
    void read(istream&); // utility function for overloading input operator
    void display(ostream&); // utility function for overloading output operator
    int calculateSalary(int); // function that calculates montly salary of waiter
    
};

// overloaded operators

istream& operator>> (istream&, Employee&);

ostream& operator<< (ostream&, Employee&);

#endif