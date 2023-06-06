#include <iostream>
#include <string>
#include <fstream>

#include "Employee.h"
#include "Salary.h"
#include "Commission.h"
#include "BaseCommission.h"

//Updated: 6/6/2023

using namespace std;

void decision(const int& value);
void valueCheck(string& init, bool& check);
bool isnumber(const string& value);

int main() {
    string name = " ";
    string last = " ";
    string input = "";

    int age = 0;
    int id = 0;
    int input_num = 0;

    double income = 0;
    double rates = 0;
    double sales_in = 0;
    double basePay = 0;


    bool flag = true;

    cout << "Welcome to Payroll System" << endl;
    cout << "\nWhat would you like to do? (Enter a number between 1 and 3): "<< endl;
    cout << "1. Input Weekly Salary\n2. Input Commission\n3. Input Commission + Base pay" << endl;
    cout << "Input: ";
    getline(cin, input);

    flag = isnumber(input);

    while (flag == false || stoi(input) < 1 || stoi(input) > 3) {
        valueCheck(input, flag);
        flag = isnumber(input);
    }

    input_num = stoi(input);
    decision(input_num);

    

}

void decision(const int& value) {
    string first_name;
    string last_name;
    
    int age_value = 0;
    int id_value = 0;

    double wage = 0.0;
    double rate = 0.0;
    double sales = 0.0;
    double salaryBase = 0.0;
    char choice;
    bool checkIn = true;
    

    fstream my_file;
    my_file.open("Employee Records",fstream::app);
 
    while (checkIn == true) {
        cout << "\nPlease Enter first Name of the employee: ";
        cin >> first_name;
        cout << "\nPlease Enter " << first_name << "'s last name: ";
        cin >> last_name;
        cout << "\nEnter " << first_name << "'s age: ";
        cin >> age_value;
        cout << "\nEnter " << first_name << "'s ID Number: ";
        cin >> id_value;

        if (value == 1) {
            cout << "\nWhat is " << first_name << "'s weekly pay? ";
            cin >> wage;
            cout << "\nInformation Recieved: " << endl;

            Salary employee{ first_name,last_name,age_value,id_value,wage };
            my_file << "\nName: " << employee.getName() << " " << employee.getLastName()
                << "\nAge: " << employee.getAge() << "\nID: " << employee.getId()
                << "\nWeekly Salary: $" << employee.earning() << "\n ";

        }
        else {
            cout << "\nWhat is " << first_name << "'s commission rate? ";
            cin >> rate;
            cout << "\nWhat is " << first_name << "'s gross sales? ";
            cin >> sales;

            if (value == 2) {
                cout << "\nInformation Recieved: " << endl;
                Commission employee{ first_name,last_name,age_value,id_value,rate,sales };
                my_file << "Name: " << employee.getName() << " " << employee.getLastName()
                    << "\nAge: " << employee.getAge() << "\nID: " << employee.getId()
                    << "\nCommission Rate: " << employee.getRate()
                    << "\nCommission Sales: " << employee.getSales()
                    << "\nTotal Earnings: $" << employee.earning() << "\n ";
            }
            else {
                cout << "\nWhat is the base salary? ";
                cin >> salaryBase;
                cout << "\nInformation Recieved: " << endl;
                BaseCommission employee{ first_name,last_name,age_value,id_value,rate,sales, salaryBase };
                my_file << "Name: " << employee.getName() << " " << employee.getLastName()
                    << "\nAge: " << employee.getAge() << "\nID: " << employee.getId()
                    << "\nCommission Rate: " << employee.getRate()
                    << "\nCommission Sales: " << employee.getSales()
                    << "\nSalary Base: $" << employee.getBase()
                    << "\nTotal Earnings: $" << employee.earning() << "\n ";
            }

        }
        cout << "\nDo you want to add more employee's?(Y/N) ";
        cin >> choice;

        if (tolower(choice) == 'n') {
            checkIn = false;
        }

    }
    cout << "\nExiting...";
    my_file.close();
}


void valueCheck(string& init, bool& check) {
    check = isnumber(init);
    cout << "Please input 1, 2, or 3\nInput: ";
    getline(cin, init);
}

bool isnumber(const string& value) {
    for (auto& s : value) {
        if (isdigit(s) == 0) {
            return false;
        }
    }
    return true;
}