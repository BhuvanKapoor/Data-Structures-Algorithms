#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    system("cls");
    int row,col;

    cout << "\nEnter number of rows : ";
    cin >> row;

    cout << "\nEnter number of columns : ";
    cin >> col;

    int size = row * col;
    int arr[size];
  
    cout << "\nEnter an array with " << size << " elements : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    int matrix [row][col], k = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = arr[k++];

    cout << "\nRow Major Matrix " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
    return 0;
}
