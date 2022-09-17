#include <iostream>

using namespace std;

int main () {
    system("cls");
    int i, k, temp, size;

    cout << "\n******************************";
    cout << "\n\tSELECTION SORT";
    cout << "\n******************************";

    cout << "\nEnter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "\nEnter the elements of the array : ";
    for (i = 0; i < size; i++) 
        cin >> arr[i];

    cout << "\nUnsorted array : ";
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    for (i = 0; i < size-1; i++) {
        for (k = i+1; k < size; k++) {
            if (arr[k] < arr[i]) {
                temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << "\nSorted array : ";
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}