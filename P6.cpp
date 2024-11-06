#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to hold personal records
struct PersonalRecord {
    string name;
    string dob; // Date of Birth in format "YYYY-MM-DD"
    string phone;

    // Overloading the less than operator for sorting by name
    bool operator<(const PersonalRecord &other) const {
        return name < other.name;
    }
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
    auto it = find_if(records.begin(), records.end(), 
                      [&name](const PersonalRecord &record) {
                          return record.name == name;
                      });

    if (it != records.end()) {
        cout << "Record found: Name: " << it->name 
             << ", DOB: " << it->dob 
             << ", Phone: " << it->phone << endl;
    } else {
        cout << "Record not found for name: " << name << endl;
    }
}

int main() {
    vector<PersonalRecord> records;
    int n;

    cout << "Enter number of records: ";
    cin >> n;

    // Input records
    for (int i = 0; i < n; ++i) {
        PersonalRecord record;
        cout << "Enter name: ";
        cin >> record.name; // This will read until the first space
        cout << "Enter DOB (YYYY-MM-DD): ";
        cin >> record.dob; // Same here
        cout << "Enter phone number: ";
        cin >> record.phone; // Same here
        records.push_back(record);
    }

    // Sort records by name
    sort(records.begin(), records.end());

    // Display sorted records
    displayRecords(records);

    // Search for a record
    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName; // Reads until the first space
    searchRecord(records, searchName);

    return 0;
}
//O/p:
Enter number of records: 3
Enter name: Aditi Sharma
Enter DOB (YYYY-MM-DD): 1995-07-20
Enter phone number: 9876543210
Enter name: Vikram Singh
Enter DOB (YYYY-MM-DD): 1992-03-15
Enter phone number: 9123456780
Enter name: Priya Patel
Enter DOB (YYYY-MM-DD): 1990-11-30
Enter phone number: 9988776655

Sorted Personal Records:
Name: Aditi Sharma, DOB: 1995-07-20, Phone: 9876543210
Name: Priya Patel, DOB: 1990-11-30, Phone: 9988776655
Name: Vikram Singh, DOB: 1992-03-15, Phone: 9123456780

Enter name to search: Priya Patel
Record found: Name: Priya Patel, DOB: 1990-11-30, Phone: 9988776655

