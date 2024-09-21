#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 100; // Maximum number of employees in a department
const int MAX_DAYS = 30;       // Maximum number of days to track attendance

// Employee class
class Employee {
private:
    int employeeID;
    string name;
    string department;
    string role;
    double salary; // To accommodate both full-time and part-time employees
    double hourlyRate;
    int hoursWorked;

public:
    Employee(int id = 0, string n = "", string dept = "", string r = "", double s = 0.0, double rate = 0.0, int hours = 0)
        : employeeID(id), name(n), department(dept), role(r), salary(s), hourlyRate(rate), hoursWorked(hours) {}

    void setDetails() {
        cout << "Enter name of employee: ";
        cin >> name;
        cout << "Enter department name: ";
        cin >> department;
        cout << "Enter ID of Employee: ";
        cin >> employeeID;
        cout << "Enter role of Employee: ";
        cin >> role;
        
        cout << "Is this a full-time employee? (y/n): ";
        char isFullTime;
        cin >> isFullTime;
        
        if (isFullTime == 'y') {
            cout << "Enter annual salary of Employee: ";
            cin >> salary;
        } else {
            cout << "Enter hourly rate of Employee: ";
            cin >> hourlyRate;
            cout << "Enter hours worked by Employee: ";
            cin >> hoursWorked;
        }
    }

    void displayDetails() const {
        cout << "ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Role: " << role << endl;
        if (salary > 0) {
            cout << "Annual Salary: " << salary << endl;
        } else {
            cout << "Hourly Rate: " << hourlyRate << ", Hours Worked: " << hoursWorked << endl;
        }
    }

    int getEmployeeID() const {
        return employeeID;
    }
};

// Department class
class Department {
private:
    string departmentName;
    Employee* employees[MAX_EMPLOYEES];
    bool attendance[MAX_EMPLOYEES][MAX_DAYS];
    int employeeCount;

public:
    Department(const string& name) : departmentName(name), employeeCount(0) {
        for (int i = 0; i < MAX_EMPLOYEES; ++i) {
            employees[i] = nullptr;
            for (int j = 0; j < MAX_DAYS; ++j) {
                attendance[i][j] = false; // Initialize all attendance records to false (absent)
            }
        }
    }

    void addEmployee(Employee* emp) {
        if (employeeCount < MAX_EMPLOYEES) {
            employees[employeeCount++] = emp;
        } else {
            cout << "Employee list is full." << endl;
        }
    }

    void markAttendance(int employeeID, int day) {
        if (day < 0 || day >= MAX_DAYS) {
            cout << "Invalid day." << endl;
            return;
        }
        
        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i]->getEmployeeID() == employeeID) {
                attendance[i][day] = true;
                cout << "Attendance marked for Employee ID " << employeeID << " on day " << day + 1 << endl;
                return;
            }
        }
        cout << "Employee not found." << endl;
    }

    void printAttendance(int employeeID) const {
        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i]->getEmployeeID() == employeeID) {
                cout << "Attendance for Employee ID " << employeeID << ": ";
                for (int j = 0; j < MAX_DAYS; ++j) {
                    cout << (attendance[i][j] ? "P " : "A ");
                }
                cout << endl;
                return;
            }
        }
        cout << "Employee not found." << endl;
    }

    void generateEmployeeReports() const {
        cout << "\nGenerating Employee Reports:\n";
        for (int i = 0; i < employeeCount; ++i) {
            employees[i]->displayDetails();
            cout << "------------------------------" << endl;
        }
    }

    ~Department() {
        // Clean up dynamically allocated memory
        for (int i = 0; i < employeeCount; ++i) {
            delete employees[i];
        }
    }
};

int main() {
    cout << "---------------------------" << endl;
    cout << "-Employee Management System-" << endl;
    cout << "---------------------------" << endl;

    Department techDepartment("Technology");

    while (true) {
        int choice;
        cout << "\nMenu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Mark Attendance" << endl;
        cout << "3. Print Attendance" << endl;
        cout << "4. Generate Employee Reports" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee* emp = new Employee();
                emp->setDetails();
                techDepartment.addEmployee(emp);
                break;
            }
            case 2: {
                int empID, day;
                cout << "Enter Employee ID to mark attendance: ";
                cin >> empID;
                cout << "Enter day (1 to " << MAX_DAYS << "): ";
                cin >> day;
                techDepartment.markAttendance(empID, day - 1); // Adjust for 0-based index
                break;
            }
            case 3: {
                int empID;
                cout << "Enter Employee ID to print attendance: ";
                cin >> empID;
                techDepartment.printAttendance(empID);
                break;
            }
            case 4: {
                techDepartment.generateEmployeeReports();
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}