#include <iostream>
#include <string>
using namespace std;

class Publication {
public:
    string title;
    float price;
    void input() {
        try {
            cout << "Enter the title of the publication: ";
            cin >> title;

            cout << "Enter the price of the publication: ";
            cin >> price;

            if (price < 0) 
            throw invalid_argument("Price cannot be negative.");

        } catch (invalid_argument &e) {
            cout << "Error: " << e.what() << " Setting all values to zero.\n";
            title = "";
            price = 0;
        }
    }
    void display() const {
        cout << "Title: " << title << "\nPrice: $" << price << endl;
    }
};

class Book : public Publication {
public:
    int pages;
    void pagecount() {
        try {
            cout << "Enter the number of pages in the book: ";
            cin >> pages;

            if (pages < 0) throw invalid_argument("Page count cannot be negative.");

        } catch ( invalid_argument &e) {
            cout << "Error: " << e.what() << " Setting all values to zero.\n";
            title = "";
            price = 0;
            pages = 0;
        }
    }
    void show() const {
        display();
        cout << "Page count: " << pages << endl;
    }
};
class Tape : public Publication {
public:
    float time;

    void timecount() {
        try {
            cout << "Enter the playing time of the tape in minutes: ";
            cin >> time;

            if (time < 0) throw invalid_argument("Playing time cannot be negative.");

        } catch ( invalid_argument &e) {
            cout << "Error: " << e.what() << " Setting all values to zero.\n";
            title = "";
            price = 0;
            time = 0;
        }
    }
    void shows() const {
        display();
        cout << "Playing time: " << time << " minutes" << endl;
    }
};
int main() {
    Book book;
    Tape tape;
    // Input for book
    cout << "\nEnter details for the book:\n";
    book.input();
    book.pagecount();
    // Input for tape
    cout << "\nEnter details for the tape:\n";
    tape.input();
    tape.timecount();
    // Display the details of book and tape
    cout << "\nBook Details:\n";
    book.show();
    cout << "\nTape Details:\n";
    tape.shows();
    return 0;
}
//O/p:
Enter details for the book:
Enter the title of the publication: Life
Enter the price of the publication: 30
Enter the number of pages in the book: 250\
Book Details:
Title: Life
Price: $30
Page count: 250