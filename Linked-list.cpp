#include <iostream>

using namespace std;

struct node {
    char info;
    struct node *next;
}n;

struct node *start;

bool isempty(struct node *p) {
    if (p->next == NULL) 
        return true;
    else
        return false;
}

void freenode(struct node *q) {
    free(q);
}

struct node* getnode() {
    struct node *p;
    p = (struct node*) malloc(sizeof (struct node));
    return p;
}

void insertafter (struct node *p, char insert_value) {
    struct node *q;
    q = getnode();
    q->info = insert_value;
    q->next = p->next;
    p->next = q;
}

char deleteafter (struct node *p) {
    struct node *q;
    char ch;
    q = p->next;
    ch = q->info;
    p->next = q->next;
    freenode(q);
    return ch;
}

void display (struct node *p) {
    cout << "\nList : ";
    // p = start;
    // p->next = start->next;
    do {
        p = p->next;
        cout << p->info << " ";
    }while (p->next != NULL);
}

int main () {
    int option;
    char choose = 'y',insert_value,search_info,delete_value,removed_value;
    struct node *p;
    // p = start;
    struct node *start = NULL;
    do {
        // system("cls");
        cout << "***************************" << endl;
        cout << "\tLINKED LIST" << endl;
        cout << "***************************" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> option;
        switch (option) {
            case 1: if (isempty(&n)) {
                        cout << "\nEnter the value you want to insert : ";
                        cin >> insert_value;
                        insertafter (&n, insert_value);
                        display(&n);
                    } 
                    else {
                        // cout << "\nEnter the value you want to insert after : ";
                        // cin >> search_info;
                        cout << "\nEnter the value (insert) : ";
                        cin >> insert_value;
                        // p->next = start->next;
                        // while (p->info != search_info) {
                        //     p = p->next;
                        //     cout << "while test";
                        // }
                        insertafter (&n,insert_value);
                        // display(&n);
                    }
                break;
            
            case 2: if (!isempty(&n)) {
                        // cout << "\nEnter the value (delete) : ";
                        // cin >> delete_value;
                        // p = start;
                        // while (p->info != delete_value)
                        //     p = p->next;
                        removed_value = deleteafter (&n);
                        cout << "\nRemoved value : " << removed_value;
                        display (&n);
                    } 
                    else    
                        cout << "\nList is Empty !!";
                break;

            case 3: if (!isempty (&n))
                        display(&n);
                    else    
                        cout << "\nList is Empty !!";
                break;

            case 4: cout << "\nExiting";
                    exit(0);
                break;
            
            default: cout << "\nInvalid choice ";
            break;
        }
        cout << "\nDo you want to continue (Y|N) : " ;
        cin >> choose;
    } while (choose == 'Y' || choose == 'y');
    return 0;
}