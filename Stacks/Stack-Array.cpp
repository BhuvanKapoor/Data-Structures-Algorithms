#include <iostream>

using namespace std;

struct stck {
    char item[5];
    int top;
}s;

bool isFull (struct stck *p) {
    if (p->top == 4)
        return true;
    return false;
}

bool isEmpty (struct stck *p) {
    if (p->top == -1)
        return true;
    return false;
}

void push (struct stck *p, char insert_value) {
    if (!isFull(&s)) {
        p->top = p->top + 1;
        p->item[p->top] = insert_value;
    }
    else 
        cout << "\nStack is Full !!";
}

char pop (struct stck *p) {
    char removed_value;
    if (!isEmpty(&s)) {
        removed_value = p->item[p->top];
        p->top = p->top - 1;
        return removed_value;
    }
    else
        cout << "\nStack is Empty !!";
    return 0;
}

void peek (struct stck *p) {
    if (!isEmpty(&s)) 
        cout << "\nTop element : " << p->item[p->top];
    else
        cout << "\nStack is Empty !!";
}

void display (struct stck *p) {
    if (!isEmpty(&s)) {
        cout << "\nStack : ";   
        for (int i = 0; i <= p->top; i++)
            cout << p->item[i] << " ";
    }
    else
        cout << "\nStack is Empty !!";
}

int main () {
    int option;
    char choose,insert_value,removed_value;
    s.top = -1;

    do {
        system("cls");
        cout << "\n*********************";
        cout << "\n\tSTACK";
        cout << "\n*********************";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice : ";
        cin >> option;

        switch (option) {
            case 1: if (!isFull(&s)) {
                        cout << "\nEnter new element : ";
                        cin >> insert_value;
                        push (&s, insert_value);
                    }
                    else
                        cout << "\nStack is Full !!";
                break;
            
            case 2: if (!isEmpty(&s)) {
                        removed_value = pop (&s);
                        cout << "\nPopped Element : " << removed_value;
                    }
                    else
                        cout << "\nStack is Empty !!";
                break;

            case 3: peek (&s);
                break;

            case 4: display (&s);
                break;

            case 5: cout << "\nExitting !!";
                    exit (0);
                break;       

            default: cout << "\nWarning: Please enter a valid choice !!";
                break;
        }
        cout << "\nDo you want to continue (Y|N) : ";
        cin >> choose;
    } while (choose == 'y' || choose == 'Y');
    return 0;
}
