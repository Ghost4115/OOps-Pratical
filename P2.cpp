#include <iostream>
#include <string>
using namespace std;

class Student {
    static int studentCount;  // Static member to keep track of student count
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicense;

public:
    // Default constructor
    Student() : rollNumber(0), division('A') {
        studentCount++;
    }

    // Parameterized constructor
    Student(string n, int roll, string sClass, char div, string dateOfBirth,
            string bg, string address, string phone, string license)
            : name(n), rollNumber(roll), studentClass(sClass), division(div),
              dob(dateOfBirth), bloodGroup(bg), contactAddress(address), phoneNumber(phone),
              drivingLicense(license) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student &student) {
        name = student.name;
        rollNumber = student.rollNumber;
        studentClass = student.studentClass;
        division = student.division;
        dob = student.dob;
        bloodGroup = student.bloodGroup;
        contactAddress = student.contactAddress;
        phoneNumber = student.phoneNumber;
        drivingLicense = student.drivingLicense;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Friend class for accessing private data
    friend class StudentDatabase;

    // Inline function to display student data
    inline void displayData() const {
        cout << "\nName: " << name << "\nRoll Number: " << rollNumber
             << "\nClass: " << studentClass << "\nDivision: " << division
             << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup
             << "\nContact Address: " << contactAddress
             << "\nPhone Number: " << phoneNumber
             << "\nDriving License: " << drivingLicense << endl;
    }

    // Static member function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Function to update student's address (using `this` pointer)
    void updateAddress(const string &newAddress) {
        this->contactAddress = newAddress;
    }

    // Function to take input from the user
    void inputData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Class: ";
        cin >> studentClass;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Contact Address: ";
        cin >> contactAddress;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        cout << "Enter Driving License Number: ";
        cin >> drivingLicense;
    }

    // Operator new and delete overloading for dynamic allocation
    void* operator new(size_t size) {
        cout << "Allocating memory using new operator\n";
        return malloc(size);
    }
    
    void operator delete(void* ptr) {
        cout << "De-allocating memory using delete operator\n";
        free(ptr);
    }
};

int Student::studentCount = 0;  // Initialize static member

class StudentDatabase {
public:
    // Function to display all student details using friend access
    static void showStudentDetails(const Student &student) {
        student.displayData();
    }
};

int main() {
    // Dynamically creating a Student object using new
    Student* student1 = new Student();

    // Taking input from the user
    student1->inputData();

    cout << "\nStudent Details:\n";
    StudentDatabase::showStudentDetails(*student1);

    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

    // Updating address using `this` pointer
    string newAddress;
    cout << "\nEnter updated address: ";
    cin >> newAddress;
    student1->updateAddress(newAddress);

    cout << "\nUpdated Address:\n";
    StudentDatabase::showStudentDetails(*student1);

    // Deleting dynamically allocated student object
    delete student1;
    cout << "\nTotal Students after deletion: " << Student::getStudentCount() << endl;

    return 0;
}
//O/p:
Enter Name: Alice
Enter Roll Number: 101
Enter Class: 10
Enter Division: A
Enter Date of Birth (DD/MM/YYYY): 15/08/2005
Enter Blood Group: O+
Enter Contact Address: 123 Main St
Enter Phone Number: 9876543210
Enter Driving License Number: DL12345

Student Details:
Name: Alice
Roll Number: 101
Class: 10
Division: A
DOB: 15/08/2005
Blood Group: O+
Contact Address: 123 Main St
Phone Number: 9876543210
Driving License: DL12345

Total Students: 1

Enter updated address: 456 Elm St

Updated Address:
Name: Alice
Roll Number: 101
Class: 10
Division: A
DOB: 15/08/2005
Blood Group: O+
Contact Address: 456 Elm St
Phone Number: 9876543210
Driving License: DL12345

De-allocating memory using delete operator
Total Students after deletion: 0
