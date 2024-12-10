#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to hold personal records
struct PersonalRecord {
    string name, dob, phone;
};

// Function to display records
void displayRecords(const vector<PersonalRecord> &records) {
    cout << "\nPersonal Records:\n";
    for (const auto &record : records) {
        cout << "Name: " << record.name 
             << ", DOB: " << record.dob 
             << ", Phone: " << record.phone << endl;
    }
}

// Function to search for a record by name
void searchRecord(const vector<PersonalRecord> &records, const string &name) {
    for (const auto &record : records) {
        if (record.name == name) {
            cout << "Record found: Name: " << record.name 
                 << ", DOB: " << record.dob 
                 << ", Phone: " << record.phone << endl;
            return;
        }
    }
    cout << "Record not found for name: " << name << endl;
}

int main() {
    int n;
    cout << "Enter number of records: ";
    cin >> n;

    vector<PersonalRecord> records(n);

    // Input records
    for (int i = 0; i < n; ++i) {
        cout << "Enter name: ";
        cin >> records[i].name;
        cout << "Enter DOB (YYYY-MM-DD): ";
        cin >> records[i].dob;
        cout << "Enter phone number: ";
        cin >> records[i].phone;
    }

    // Sort records by name
    sort(records.begin(), records.end(), [](const PersonalRecord &a, const PersonalRecord &b) {
        return a.name < b.name;
    });

    // Display sorted records
    displayRecords(records);

    // Search for a record
    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName;
    searchRecord(records, searchName);

    return 0;
}
