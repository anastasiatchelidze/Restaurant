#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include "employee.h"

using namespace std;

int main() {

    const int N = 6;
    array<Employee*,N>employees;
    Employee* Owner = new Employee("Anastasia", "01004060", 'O', 15000);
    employees[0] = Owner;
    employees[1] = new Chef("Mark", "03004842", "Canadian");
    employees[2] = new Chef("Yuta", "06700930", "Japanese");
    int tips1 = -1, tips2, tips3;
    while (tips1 < 0 || tips2 < 0 || tips3 < 0) {
        cout << "Please enter amount of tips of waiters this month: ";
        cin >> tips1 >> tips2 >> tips3;
        if (tips1 < 0 || tips2 < 0 || tips3 < 0) {
            cout << "Invalid numbers. Please try again." << endl;
        }
    }
    
    employees[3] = new Waiter("Johnny", "04201057", 3, tips1);
    employees[4] = new Waiter("Elly", "09001831", 5, tips2);
    employees[5] = new Waiter("Jay", "07005126", 2, tips3);
    
    int profit;
    
    cout << "Please input the profit of restaurant this month: ";
    cin >> profit;
    
    for (auto item:employees) {
        cout << item->getName() << "'s salary this month is: " << item->calculateSalary(profit) << endl;
    }
    
    return 0;
}