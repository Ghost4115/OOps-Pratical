#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("myFile.txt");
    outputFile << "I am creating a sample text file.\n";
    outputFile << "Hello, world!\n";
    outputFile << "Goodbye!\n";
    outputFile.close();

    ifstream inputFile("myFile.txt");
    char ch;
    while (inputFile.get(ch)) {
        cout << ch;
    }
    inputFile.close();

    return 0;
}
//O/p:
I am creating a sample text file.
Hello, world!
Goodbye!
