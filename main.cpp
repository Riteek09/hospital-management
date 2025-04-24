#include <iostream>
#include <string>
using namespace std;

// Node structure for Patient
struct Patient {
    int id;
    string name;
    int age;
    string diagnosis;
    Patient* next;
};

class HospitalManagementSystem {
private:
    Patient* head;

public:
    HospitalManagementSystem() : head(nullptr) {}

    // Add a new patient record
    void addPatient(int id, string name, int age, string diagnosis) {
        Patient* newPatient = new Patient{id, name, age, diagnosis, nullptr};

        if (head == nullptr) {
            head = newPatient;
        } else {
            Patient* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        cout << "Patient added successfully!\n";
    }

    // Delete a patient record by ID
    void deletePatient(int id) {
        if (head == nullptr) {
            cout << "No records found!\n";
            return;
        }

        Patient* temp = head;
        Patient* prev = nullptr;

        // If head node is to be deleted
        if (temp != nullptr && temp->id == id) {
            head = temp->next;
            delete temp;
            cout << "Patient deleted successfully!\n";
            return;
        }

        // Search for the patient
        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Patient not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Patient deleted successfully!\n";
    }

    // Search for a patient by ID
    void searchPatient(int id) {
        Patient* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "\nPatient Found:\n";
                cout << "ID: " << temp->id << "\n";
                cout << "Name: " << temp->name << "\n";
                cout << "Age: " << temp->age << "\n";
                cout << "Diagnosis: " << temp->diagnosis << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found!\n";
    }

    // Display all patient records
    void displayPatients() {
        Patient* temp = head;
        if (temp == nullptr) {
            cout << "No records found!\n";
            return;
        }

        cout << "\n===== Patient Records =====\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->id << "\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Age: " << temp->age << "\n";
            cout << "Diagnosis: " << temp->diagnosis << "\n";
            cout << "-------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    HospitalManagementSystem hospital;
    int choice, id, age;
    string name, diagnosis;

    while (true) {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Diagnosis: ";
                cin.ignore();
                getline(cin, diagnosis);
                hospital.addPatient(id, name, age, diagnosis);
                break;
            case 2:
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                hospital.deletePatient(id);
                break;
            case 3:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                hospital.searchPatient(id);
                break;
            case 4:
                hospital.displayPatients();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}