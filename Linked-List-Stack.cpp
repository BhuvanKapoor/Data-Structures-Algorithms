#include <iostream>

using namespace std;

struct node {
    char info;
    node *next;
};

class stack {
    private:
        node *top;
    public:
        stack() {
            top = NULL;
        }

        void Insert() {
            node *ptr;
            ptr = new node;
            cout << "\nEnter the value of new node : ";
            cin >> ptr->info;
            ptr->next = NULL;
            if (top == NULL) {
                top = ptr;
            }
            else {
                ptr->next = top;
                top = ptr;
            }
            cout << "\nNode inserted Successfully !!";
        }

        void Delete() {
            node *temp;
            if(top != NULL) {
                temp = top;
                top = top->next;
                cout << "\nRemoved Node : " << temp->info;
                delete temp; 
            }
            else
                cout << "\nStack is Empty !!";
        }

        void Display() {
            node *temp;
            if (top != NULL) {
                temp = top;
                cout << "\nList : ";
                while (temp != NULL) {
                    cout << temp->info << " ";
                    temp = temp->next;
                }
            }
            else
                cout << "\nStack is Empty !!";
        }
};

int main () {
    int option;
    char choose;
    stack s;
    do {
        system("cls");
        cout << "\n***********************************";
        cout << "\n\tLINKED LIST [STACK]";
        cout << "\n***********************************";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice : ";
        cin >> option;

        switch (option) {
            case 1: s.Insert();
                break;
            
            case 2: s.Delete(); 
                break;

            case 3: s.Display();
                break;

            case 4: cout << "\nExitting !!";
                    exit(0);
                break;
            
            default : cout << "\nWarning : Please enter a valid option";
        }
        cout << "\nDo you want to continue [Y|N] : ";
        cin >> choose;
    } while (choose == 'y' || choose == 'Y');
    return 0;
}