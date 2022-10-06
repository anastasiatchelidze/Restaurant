#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee() {
    string name = "";
    string ID = "--------";
    char empClass = '-';
    int salary = 0;
}

Employee::Employee(istream& in) {
    read(in);
}

Employee::Employee(string name, string ID, char empClass, int salary) {
    if(ID.length() == 8 && (int)empClass >= 65 && (int)empClass <= 90 && salary > 0) {
        this->name = name;
        this->ID = ID;
        this->empClass = empClass;
        this->salary = salary;
    }
}

void Employee::setSalary(int salary) {
    if(salary > 0) 
        this->salary = salary;
}

int Employee::getSalary() const {
    return salary;
}

void Employee::setClass(char empClass) {
    if((int)empClass >= 65 && (int)empClass <= 90)
        this->empClass = empClass;
}

string Employee::getName() const {
    return name;
}

void Employee::read(istream& in) {
    // temporary variables for validating inputs before assigning them to data members
    string id;
    char Class;
    int Salary;
    in >> name >> id >> Class >> Salary;
    if(id.length() == 8 && (int)Class >= 65 && (int)Class <= 90 && Salary > 0) {
        ID = id;
        empClass = Class;
        salary = Salary;
    }
}

void Employee::display(ostream& out) {
    out << "Name: " << name << endl;
    out << "Employee ID: " << ID << endl;
    out << "Employee class: " << empClass << endl;
    out << "Salary: " << salary << endl;
}

int Employee::calculateSalary(int profit) {
    if (profit >= 0)
        return salary + profit*0.6;
    else
        return salary; // no profit when restaurant encounters a loss
}

istream& operator>> (istream& in, Employee& emp) {
    emp.read(in);
    return in;
}

ostream& operator<< (ostream& out, Employee& emp) {
    emp.display(out);
    return out;
}

Chef::Chef(istream& in) {
    read(in);
}

Chef::Chef(string name, string ID, string cuisine) {
    this->name = name;
    if(ID.length() == 8)
        this->ID = ID;
    empClass = 'C';
    salary = 10000;
    this->cuisine = cuisine;
}

void Chef::setCuisine(string cuisine) {
    this->cuisine = cuisine;
}

string Chef::getCuisine() const {
    return cuisine;
}

void Chef::read(istream& in) {
    string id;
    int Salary;
    char Class;
    in >> name >> id >> Class >> Salary >> cuisine;
    if(id.length() > 0)
        ID = id;
    if(Salary > 0)
        salary = Salary;
    if((int)Class >= 65 && (int)Class <= 90)
        empClass = Class;
}

void Chef::display(ostream& out) {
    out << "Name: " << name << endl;
    out << "Employee ID: " << ID << endl;
    out << "Employee class: " << empClass << endl;
    out << "Salary: " << salary << endl;
    out << "Expertised cuisine: " << cuisine << endl;
}

int Chef::calculateSalary(int profit) {
    if (profit >= 0)
        return salary + profit*0.2;
    else
        return salary; // no profit when restaurant encounters a loss
}

Waiter::Waiter(istream& in) {
    read(in);
}

Waiter::Waiter(string name, string ID, int expYears, int tips) {
    this->name = name;
    if(ID.length() == 8)
        this->ID = ID;
    empClass = 'W';
    salary = 3000;
    if(expYears >= 0)
        this->expYears = expYears;
    if(tips >= 0)
        this->tips = tips;
}

void Waiter::setExpYears(int ExpYears) {
    if(ExpYears >= 0)
        expYears = ExpYears;
}

int Waiter::getExpYears() const {
    return expYears;
}

void Waiter::setTips(int Tips) {
    if(Tips >= 0)
        tips = Tips;
}

int Waiter::getTips() const {
    return tips;
}

void Waiter::read(istream& in) {
    string id;
    char Class;
    int Salary;
    int ExpYears, Tips;
    in >> name >> id >> empClass >> Salary >> ExpYears >> Tips;
    if(id.length() == 8)
        ID = id;
    if((int)Class >= 65 && (int)Class <= 90)
        empClass = Class;
    if(Salary > 0)
        salary = Salary;
    if(ExpYears >= 0)
        expYears = ExpYears;
    if(Tips >= 0)
        tips = Tips;
}

void Waiter::display(ostream& out) {
    out << "Name: " << name << endl;
    out << "Employee ID: " << ID << endl;
    out << "Employee class: " << empClass << endl;
    out << "Salary: " << salary << endl;
    out << "Experience years: " << expYears << endl;
}

int Waiter::calculateSalary(int profit) {
    return salary + tips;
}