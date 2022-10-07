#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1) 
        return n;
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main () {
    system("cls");

    int terms,i=0;

    cout << "\n********************************";
    cout << "\n\tFIBONACCI SERIES";
    cout << "\n********************************";

    cout << "\nEnter the number of terms : ";
    cin >> terms;

    cout << "Series : ";
    while (i < terms) {
        cout << fibonacci(i) << " ";
        i++;
    }

    return 0;
}