#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatting output

// --- Class Definition: Data Structure ---
class AssignmentData {
public:
    int id;
    std::string description;
    double progress;

    AssignmentData(int _id, std::string _desc, double _prog) 
        : id(_id), description(_desc), progress(_prog) {}
};

// --- Class Definition: Engine Logic ---
class ProjectManager {
private:
    std::vector<AssignmentData> database;

public:
    void addRecord(int id, std::string desc, double prog) {
        database.emplace_back(id, desc, prog);
    }

    void displayAll() {
        std::cout << "\n-----------------------------------" << std::endl;
        std::cout << std::left << std::setw(5) << "ID" 
                  << std::setw(20) << "Description" 
                  << "Progress" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        
        for (const auto& item : database) {
            std::cout << std::left << std::setw(5) << item.id 
                      << std::setw(20) << item.description 
                      << std::fixed << std::setprecision(1) << item.progress << "%" 
                      << std::endl;
        }
        std::cout << "-----------------------------------\n" << std::endl;
    }
};

// --- Main Function ---
int main() {
    ProjectManager pm;

    std::cout << "=== Assignment Manager Loaded ===\n" << std::endl;

    // Simulate Week 1 Progress
    pm.addRecord(1, "Project Setup", 100.0);
    pm.addRecord(2, "Core Logic", 50.0);

    // Display current state
    pm.displayAll();

    std::cout << "Program finished successfully." << std::endl;

    return 0;
}
