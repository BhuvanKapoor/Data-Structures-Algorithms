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
    do {
        p = p->next;
        cout << p->info << " ";
    } while (p->next != NULL);
}

int main () {
    int option;
    char choose = 'y',insert_value,search_info,delete_value,removed_value;
    struct node *p;
    struct node *start = NULL;
    do {
        system("cls");
        cout << "\n**********************************";
        cout << "\n\tLINKED LIST [STACK]";
        cout << "\n**********************************";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice : ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter the value you want to insert : ";
                    cin >> insert_value;
                    insertafter (&n, insert_value);
                break;
            
            case 2: if (!isempty(&n)) {
                        removed_value = deleteafter (&n);
                        cout << "\nRemoved value : " << removed_value;
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
            
            default: cout << "\nWarning : Please enter a valid choice !!";
            break;
        }
        cout << "\nDo you want to continue [Y|N] : " ;
        cin >> choose;
    } while (choose == 'Y' || choose == 'y');
    return 0;
}
