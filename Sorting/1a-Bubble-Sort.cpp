#include <iostream>

using namespace std;

void sorting(int array[], int size_array) {
    int temp;

    for (int i = 0; i < size_array - 1; i++) {
        for (int j=0; j < size_array - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void display(int array[],int size_array) {
    cout << "\nSorted array : ";
    for (int i = 0; i < size_array; i++)
        cout << array[i] << " ";
}

int main() {
    int i,j,size_array;
    char choose;

    do {
        system("cls");
        cout << "\n***************************";
        cout << "\n\tBUBBLE SORT";
        cout << "\n***************************";

        cout << "\nEnter the size of the array: ";
        cin >> size_array;

        int array[size_array],unsorted_array[size_array];

        cout << "\nEnter the elements of the array: ";
        for (i = 0; i < size_array; i++) 
            cin >> array[i];

        for (i = 0; i < size_array; i++)
            unsorted_array[i] = array[i];
        
        cout << "\nUnsorted Array : ";
        for (i=0 ; i < size_array; i++)
            cout << unsorted_array[i] << " ";
        
        sorting (array,size_array);
        display (array,size_array);
    } while (choose == 'y' || choose == 'Y');
    return 0;
}
