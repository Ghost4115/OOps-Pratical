#include <iostream>
using namespace std;

// Template function for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Template function to display the array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int intSize = 5;
    const int floatSize = 5;

    // Integer array
    int intArr[intSize];
    cout << "Enter " << intSize << " integers:\n";
    for (int i = 0; i < intSize; ++i) {
        cin >> intArr[i];
    }

    // Float array
    float floatArr[floatSize];
    cout << "\nEnter " << floatSize << " floats:\n";
    for (int i = 0; i < floatSize; ++i) {
        cin >> floatArr[i];
    }

    // Sorting integer array
    selectionSort(intArr, intSize);
    cout << "\nSorted integer array:\n";
    displayArray(intArr, intSize);

    // Sorting float array
    selectionSort(floatArr, floatSize);
    cout << "\nSorted float array:\n";
    displayArray(floatArr, floatSize);

    return 0;
}
//O/p:
Enter 5 integers:
3 1 4 1 5

Enter 5 floats:
2.718 3.14 1.618 0.577 1.414

Sorted integer array:
1 1 3 4 5 

Sorted float array:
0.577 1.414 1.618 2.718 3.14 
