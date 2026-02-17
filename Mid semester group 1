c++code implementation 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

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

public:
    void addStudent(string id, string name) {
        studentList.push_back(Student(id, name));
    }

    void takeAttendance() {
        cout << "\n--- Taking Attendance (Enter 1 for Present, 0 for Absent) ---\n";
        for (auto& student : studentList) {
            int status;
            cout << student.name << " (" << student.id << "): ";
            cin >> status;
            student.isPresent = (status == 1);
        }
        cout << "Attendance recorded.\n";
    }

    void generateReport() {
        cout << "\n--- Attendance Report ---\n";
        cout << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Status" << endl;
        cout << "----------------------------------------\n";
        for (const auto& student : studentList) {
            cout << setw(10) << student.id 
                 << setw(20) << student.name 
                 << setw(10) << (student.isPresent ? "Present" : "Absent") << endl;
        }
    }
};

int main() {
    AttendanceManager manager;

    // Pre-populating with some sample data
    manager.addStudent("S001", "Alice Smith");
    manager.addStudent("S002", "Bob Jones");
    manager.addStudent("S003", "Charlie Brown");

    int choice;
    do {
        cout << "\n1. Take Attendance\n2. Generate Report\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.takeAttendance(); break;
            case 2: manager.generateReport(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
