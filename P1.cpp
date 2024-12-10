//(a+bi)×(c+di)=(a×c−b×d)+(a×d+b×c)i
#include <iostream>
using namespace std;

class Complex {
public:
    float real;
    float img;

    // Default constructor to initialize complex number to 0 + 0i
    Complex() : real(0), img(0) {}

    // Overload + operator to add two complex numbers
    Complex operator+(const Complex& other) {
        Complex temp;
        temp.real = this->real + other.real;
        temp.img = this->img + other.img;
        return temp;
    }

    // Overload * operator to multiply two complex numbers
    Complex operator*(const Complex& other) {
        Complex temp;
        temp.real = this->real * other.real - this->img * other.img;
        temp.img = this->real * other.img + this->img * other.real;
        return temp;
    }

    // Function to print complex number in the format a + bi
    void print() const {
        cout << real;
        if (img >= 0) 
            cout << " + " << img << "i" << endl;
        else 
            cout << " - " << -img << "i" << endl;
    }
};

int main() {
    Complex c1, c2, c3, c4;

    // Input for the first complex number
    cout << "Enter the real part of the first complex number: ";
    cin >> c1.real;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> c1.img;

    // Input for the second complex number
    cout << "Enter the real part of the second complex number: ";
    cin >> c2.real;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> c2.img;

    // Display the complex numbers
    cout << "The first complex number: ";
    c1.print();
    cout << "The second complex number: ";
    c2.print();

    // Addition and multiplication
    c3 = c1 + c2;
    c4 = c1 * c2;

    // Display the results
    cout << "The addition is: ";
    c3.print();
    cout << "The multiplication is: ";
    c4.print();

    return 0;
}


//O/P:
Enter the real part of the first complex number:
3
Enter the imaginary part of the first complex number:
4
Enter the real part of the second complex number:
1
Enter the imaginary part of the second complex number:
2
The first complex number: 3+4i
The second complex number: 1+2i
The addition is: 4+6i
The multiplication is: -5+10i
