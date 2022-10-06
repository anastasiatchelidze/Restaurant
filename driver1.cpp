#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include "employee.h"

using namespace std;

int main() {

    const int N = 6;
    array<Employee*,N>employees;
    ifstream fin("emps.txt");
    Employee* Owner = new Employee(fin);
    employees[0] = Owner;
    
    for(int i = 1; i < 3; i++) {
        Employee* temp = new Chef(fin);
        employees[i] = temp;
    }
    
    for(int i = 3; i < 6; i++) {
        Employee* temp = new Waiter(fin);
        employees[i] = temp;
    }
    
    int profitInMay = 6000;
    
    for (auto item:employees) {
        cout << *item;
        cout << "Salary in May: " << item->calculateSalary(profitInMay) << endl;
        cout << endl;
    }
    
    
    
    return 0;
}