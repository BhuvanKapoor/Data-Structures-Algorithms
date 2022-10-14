#include <iostream>

using namespace std;

struct node {
    char info;
    node *next;
};

class queue {
    private:
        node *front, *rear;
    public:
        queue() {
            front = NULL;
            rear = NULL;
        }

        void Insert() {
            node *ptr;
            ptr = new node;
            cout << "\nEnter the value of new node : ";
            cin >> ptr->info;
            ptr->next = NULL;
            if (front == NULL) {
                front = ptr;
                rear = ptr;
            }
            else {
                rear->next = ptr;
                rear = ptr;
            }
            cout << "\nNode inserted Successfully !!";
        }

        void Delete() {
            node *temp;
            if(front != NULL) {
                temp = front;
                front = front->next;
                cout << "\nRemoved Node : " << temp->info;
                delete temp; 
            }
            else
                cout << "\nQueue is Empty !!";
        }

        void Display() {
            node *temp;
            if (front != NULL) {
                temp = front;
                cout << "\nList : ";
                while (temp != NULL) {
                    cout << temp->info << " ";
                    temp = temp->next;
                }
            }
            else
                cout << "\nQueue is Empty !!";
        }
};

int main () {
    int option;
    char choose;
    queue q;
    do {
        system("cls");
        cout << "\n***************************";
        cout << "\n\tLINKED LIST";
        cout << "\n***************************";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice : ";
        cin >> option;

        switch (option) {
            case 1: q.Insert();
                break;
            
            case 2: q.Delete(); 
                break;

            case 3: q.Display();
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