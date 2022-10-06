# Restaurant

Database of the restaurant employees written in C++

This program uses the Employee class as a base class and its two derived classes: Chef and Waiter.
Employee’s class calculates monthly salary of the owner, whereas chef’s and waiter’s salaries are calculated by the methods of their own classes. When the restaurant encounters a loss (meaning the profit is less than zero), employees only receive the base of their salaries without any profits, but waiters still get their tips alongside with their base salary.

driver1.cpp reads information about employees from “emps.txt” file and populates objects based on it. As a container an array of 6 Employee pointers is declared. Then file is opened and Owner object is stored as the first element of the array. Consequently 2 Chef and 3 Waiter objects are populated. Variable profitInMay is initialized and by the range based for-loop information about each element (employee) is outputted using overloaded output operator and each employee’s salary is calculated.

In driver2.cpp objects are populated using explicit-value constructors and stored in an array of Employee object pointers. User inputs the tips of the waiters. This operation is validated because user can input negative number as tips. Therefore, while-loop runs until variable tips1, tips2 and tips3 are assigned values which are more or equal to zero. When negative number is inputted by user, corresponding error message is outputted on the screen. Consequently, user inputs the profit of particular month and finally program calculates and displays each employee’s salary in the particular month.
