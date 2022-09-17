#include <iostream>

using namespace std;

int binary_search(int array[],int search_value,int size_array) {
    int low = 0, high = size_array-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == search_value) 
            return mid;
        else if (array[mid] < search_value)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main() {
    system("cls");
    int size_array, array[size_array],search_value;

    cout << "\n*****************************";
    cout << "\n\tBINARY SEARCH";
    cout << "\n*****************************";

    cout << "\nEnter the size of the array: ";
    cin >> size_array;

    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < size_array; i++)
        cin >> array[i];

    cout << "\nEnter the element to be searched: ";
    cin >> search_value;

    int index = binary_search(array, search_value, size_array);
    if (index == -1)
        cout << "\nElement not found!!";
    else
        cout << search_value << " is found at " << index + 1 << " position.";
    
    return 0;
}