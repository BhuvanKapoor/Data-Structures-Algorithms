#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 0 || n == 1) 
        return 1;
    return n*fact(n-1);
}

int main () {
    system("cls");
    int number;

    cout << "\n*************************";
    cout << "\n\tFACTORIAL";
    cout << "\n*************************";
    
    cout << "\nEnter the number : ";
    cin >> number;

    cout << "\nFactorial of " << number << " is " << fact(number);
    return 0;
}
