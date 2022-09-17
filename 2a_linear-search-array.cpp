#include <iostream>

using namespace std;

int linear_search(int array[],int search_value, int size_array) {
    for (int i=0; i < size_array; i++) {
        if (array[i] == search_value) 
            return i;
    }
    return -1;
}

int main() {
    system("cls");
    int n,array[n],search_value,index;
    cout << "\nEnter the size of array: ";
    cin >> n;
    cout << "\nEnter the elements of array: ";
    for (int i=0; i < n; i++) 
        cin >> array[i];
    cout << "\nEnter the value to be searched: ";
    cin >> search_value;
    index = linear_search(array,search_value,n);
    if (index == -1)
        cout << "\nElement not found in the array";
    else
        cout << search_value << " found at " << index + 1 << " position";
    return 0;
}