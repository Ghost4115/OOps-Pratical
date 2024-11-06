#include <iostream>
using namespace std;

class Complex {
public:
    float real;
    float img;
    Complex() : real(0), img(0) {}
};

int main() {
    Complex c1, c2, c3, c4;
    cout << "Enter the real part of the first complex number:" << endl;
    cin >> c1.real;
    cout << "Enter the imaginary part of the first complex number:" << endl;
    cin >> c1.img;
    cout << "Enter the real part of the second complex number:" << endl;
    cin >> c2.real;
    cout << "Enter the imaginary part of the second complex number:" << endl;
    cin >> c2.img;
    cout << "The first complex number: " << c1.real << "+" << c1.img << "i" << endl;
    cout << "The second complex number: " << c2.real << "+" << c2.img << "i" << endl;
    c3.real = c1.real + c2.real;
    c3.img = c1.img + c2.img;
    c4.real = c1.real * c2.real - c1.img * c2.img;
    c4.img = c1.real * c2.img + c1.img * c2.real;
    cout << "The addition is: " << c3.real << "+" << c3.img << "i" << endl;
    cout << "The multiplication is: " << c4.real << "+" << c4.img << "i" << endl;
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
