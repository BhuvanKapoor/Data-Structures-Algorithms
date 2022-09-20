#include <iostream>

using namespace std;

struct circular_queue {
    char item[5];
    int front,rear;
}cq;

int size = 5;

bool isFull(struct circular_queue *q) {
    if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == size - 1))
        return true;
    return false; 
}

bool isEmpty(struct circular_queue *q) {
    if (q->front == -1) 
        return true;
    return false;
}

void enqueue(struct circular_queue *q,char insert_value) {
        if (q->front == -1) {
            q->front = 0;
            q->rear = 0;
        }
        else 
            (q->rear == size - 1) ? q->rear = 0 : q->rear++;           
        q->item[q->rear] = insert_value;
}

char dequeue(struct circular_queue *q) {
    char removed_value;
    removed_value = q->item[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else
        (q->front == size - 1) ? q->front = 0 : q->front++;    
    return removed_value;
}

void display(struct circular_queue *q) {
    int front = q->front, rear = q->rear;
    if (!isEmpty(&cq)) {
        if (front <= rear) {
            while (front <= rear) {
                cout << q->item[front] << " ";
                front++;
            }
        } 
        else {    
            while (front <= size - 1) {
                cout << q->item[front] << " ";
                front++;
            }
            front = 0;
            while (front <= rear) { 
                cout << q->item[front] << " ";
                front++;
            }
        }
    } else
        cout << "\nQueue is Empty !!";
}

int main() {
    int option;
    char choose,insert_value,removed_value;
    cq.front = -1;
    cq.rear = -1;
    do {
        system("cls");
        cout << "\n****************************";
        cout << "\n\tCIRCULAR QUEUE";
        cout << "\n****************************";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice : ";
        cin >> option;
        
        switch(option) {
            case 1: if (!isFull(&cq)) {
                        cout << "\nEnter a new element : ";
                        cin >> insert_value;
                        enqueue(&cq,insert_value);
                    }
                    else
                        cout << "\nQueue is Full !!";
                break;
            
            case 2: removed_value = dequeue(&cq);
                    (!isEmpty(&cq)) ? cout << "\nDeleted Element : " << removed_value : cout << "\nQueue is Empty !!";
                break;
            
            case 3: display (&cq);
                break;
            
            case 4: cout << "\nExitting !!";
                    exit(0);
                break;
            
            default : cout << "\nWarning : Please enter a valid option !!";
        }
        cout << "\nDo you want to continue [Y|N] : ";
        cin >> choose;
    } while(choose == 'y' || choose =='Y');
    return 0;
}