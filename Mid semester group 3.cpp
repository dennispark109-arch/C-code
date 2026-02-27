#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// --- Class Definition ---
// Objective: Demonstrate effective use of classes
class EngineeringComponent {
private:
    string name;
    int id;
    double cost;

public:
    EngineeringComponent(string n, int i, double c) : name(n), id(i), cost(c) {}

    // Objective: Demonstrate effective use of functions
    void display() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << "$" << fixed << setprecision(2) << cost << endl;
    }

    string getDataLine() const {
        return to_string(id) + "," + name + "," + to_string(cost);
    }
};

// --- Function Prototypes ---
void displayMenu();
void addComponent(vector<EngineeringComponent>& inv);
void saveInventory(const vector<EngineeringComponent>& inv);

int main() {
    // Objective: Demonstrate effective use of variables and arrays (vectors)
    vector<EngineeringComponent> inventory;
    int choice = 0;

    cout << "--- Engineering Inventory System ---" << endl;

    // Objective: Design a menu-driven console application
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addComponent(inventory);
                break;
            case 2:
                // Logic to view inventory would go here
                cout << "Displaying inventory..." << endl;
                break;
            case 3:
                // Objective: Implement file handling for persistent storage
                saveInventory(inventory);
                cout << "Data saved. Exiting." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    cout << "\n1. Add Component\n2. View Inventory\n3. Save & Exit\nChoice: ";
}

void addComponent(vector<EngineeringComponent>& inv) {
    string name;
    int id;
    double cost;
    cout << "Enter ID: "; cin >> id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    cout << "Enter Cost: "; cin >> cost;
    inv.emplace_back(name, id, cost);
}

void saveInventory(const vector<EngineeringComponent>& inv) {
    ofstream outFile("inventory.txt");
    for (const auto& comp : inv) {
        outFile << comp.getDataLine() << endl;
    }
    outFile.close();
}
