#include <iostream>

using namespace std;

struct node {
    char info;
    node *next;
};

class list {
    private:
        node *start;
    public:
        list() {
            start = NULL;
        }

        void insertafter() {
            char search_value;
            node *exist_ptr, *new_ptr;
            new_ptr = new node;
            if (start == NULL) {
                cout << "\nEnter info to new node : ";
                cin >> new_ptr->info;
                start = new_ptr;
                new_ptr->next = NULL;
            }
            else {
                cout << "\nEnter the node you want to insert after : ";
                cin >> search_value;
                exist_ptr = start;
                while (exist_ptr->info != search_value) 
                    exist_ptr = exist_ptr->next;
                cout << "\nEnter value of new node [] : ";
                cin >> new_ptr->info;
                new_ptr->next = exist_ptr->next;
                exist_ptr->next = new_ptr;
            }
        }

        void deleteafter() {
            char search_value, deleted_value;
            int node_count = 0;
            node *del_ptr, *exist_ptr;
            if (start != NULL) {
                exist_ptr = start;
                while(exist_ptr != NULL) {
                    exist_ptr = exist_ptr->next;
                    node_count++;
                }
                if (node_count > 1) {
                    cout << "\nEnter the node you want to delete after : ";
                    cin >> search_value;

                    exist_ptr = start;
                    while (exist_ptr->info != search_value) 
                        exist_ptr = exist_ptr->next;
                        
                    del_ptr = exist_ptr->next;
                    deleted_value = del_ptr->info;
                    exist_ptr->next = del_ptr->next;
                    cout << "\nDeleted value : " << del_ptr->info;
                    
                    delete del_ptr;
                }
                else {
                    del_ptr = start;
                    deleted_value = del_ptr->info;
                    delete del_ptr;
                    start = NULL;
                    cout << "\nDeleted value : " << deleted_value;
                }
            }
            else
                cout << "\nList is Empty !!";
        }

        void display() {
            node *temp;
            if (start != NULL) {
                temp = start;
                cout << "\nList : ";
                while (temp != NULL) {
                    cout << temp->info << " ";
                    temp = temp->next;
                }
            }
            else 
                cout << "\nList is Empty !! ";
        }
};

int main() {
    int option;
    char choose;
    list l;
    do {
        system("cls");
        cout << "\n***************************";
        cout << "\n\tLINKED LIST";
        cout << "\n***************************";
        cout << "\n1. INSERT";
        cout << "\n2. DELETE";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";
        cout << "\nEnter your choice : ";
        cin >> option;

        switch (option) {
            case 1: l.insertafter();
                break;
            
            case 2: l.deleteafter();
                break;
            
            case 3: l.display();
                break;

            case 4: exit(0);
                break;
        }
        cout << "\nDo you want to continue [Y|N] : ";
        cin >> choose;
    } while (choose == 'y' || choose == 'Y');
    return 0;
}