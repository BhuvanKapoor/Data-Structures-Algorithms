#include  <iostream>
#include <iomanip>

using namespace std;

int main () {
    system("cls");
    int non_zero,k=0;
    int matrix[3][4];

    cout << "\nEnter a 3x4 matrix : ";
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 4; j++)
            cin >> matrix[i][j];

    cout << "\nMatrix : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cout << setw(5) << matrix[i][j];
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (matrix[i][j] != 0)
                non_zero++;


    int sparce_matrix[3][non_zero];
    
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] > 0) {
                sparce_matrix[0][k] = i;
                sparce_matrix[1][k] = j;
                sparce_matrix[2][k] = matrix[i][j];
                k++;
            }
        }

    cout << "\nSparce Matrix : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < non_zero; j++)
            cout << setw(5) << sparce_matrix[i][j];
        cout << endl;
    }

    return 0;
}
