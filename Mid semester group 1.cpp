#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> // Essential for clearing the input buffer

using namespace std;

// Class representing a single student
class Student {
public:
    string id;
    string name;
    bool isPresent;

    Student(string _id, string _name) : id(_id), name(_name), isPresent(false) {}
};

// Class to manage the attendance workflow
class AttendanceManager {
private:
    vector<Student> studentList;

    // Helper function to handle invalid non-numeric inputs
    void clearInput() {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    void addStudent(string id, string name) {
        studentList.push_back(Student(id, name));
    }

    void takeAttendance() {
        if (studentList.empty()) {
            cout << "\n[!] Student list is empty. Add students first.\n";
            return;
        }

        cout << "\n--- Taking Attendance (1 for Present, 0 for Absent) ---\n";
        for (auto& student : studentList) {
            int status;
            while (true) {
                cout << "Record for " << left << setw(15) << student.name << " [" << student.id << "]: ";
                if (cin >> status && (status == 0 || status == 1)) {
                    student.isPresent = (status == 1);
                    break;
                } else {
                    cout << "    >> Invalid entry. Please enter 1 (Present) or 0 (Absent).\n";
                    clearInput();
                }
            }
        }
        cout << "[+] Attendance session complete.\n";
    }

    void generateReport() {
        if (studentList.empty()) {
            cout << "\n[!] No records to display.\n";
            return;
        }

        cout << "\n" << string(45, '=') << "\n";
        cout << left << setw(10) << "ID" << setw(20) << "NAME" << "STATUS" << endl;
        cout << string(45, '-') << "\n";
        
        for (const auto& student : studentList) {
            cout << left << setw(10) << student.id 
                 << setw(20) << student.name 
                 << (student.isPresent ? "PRESENT" : "ABSENT") << endl;
        }
        cout << string(45, '=') << endl;
    }
};

int main() {
    AttendanceManager manager;

    // Pre-populating data
    manager.addStudent("S001", "Alice Smith");
    manager.addStudent("S002", "Bob Jones");
    manager.addStudent("S003", "Charlie Brown");

    int choice = 0;
    while (choice != 3) {
        cout << "\n--- Attendance System ---\n";
        cout << "1. Take Attendance\n2. Generate Report\n3. Exit\nSelection: ";
        
        // Validate main menu input
        if (!(cin >> choice)) {
            cout << "Invalid selection. Please enter 1, 2, or 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: manager.takeAttendance(); break;
            case 2: manager.generateReport(); break;
            case 3: cout << "Exiting system. Goodbye!\n"; break;
            default: cout << "Choice out of range. Try again.\n";
        }
    }

    return 0;
}
