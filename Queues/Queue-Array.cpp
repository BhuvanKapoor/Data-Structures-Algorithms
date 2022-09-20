#include <iostream>

using namespace std;

struct queue {
    int item[5];
    int front,rear;
}q;

bool isFull(struct queue *pq) {
    if (pq->rear == 4)
        return true;
    else
        return false;
}

bool isEmpty(struct queue *pq) {
    if (pq->front == pq->rear) 
        return true;
    else
        return false;
}

void enqueue(struct queue *pq,int insert_value) {
    if (!isFull(&q)) {
        pq->rear = pq->rear + 1;
        pq->item[pq->rear] = insert_value;
    }
    else
        cout << "\nQueue is Full !!";
}

char dequeue(struct queue *pq) {
    int removed_value;
    if (!isEmpty(&q)) {
        pq->front = pq->front + 1;
        removed_value = pq->item[pq->front];
        return removed_value;
    }
    else
        cout << "\nQueue is Empty !!";
    return 0;
}

void peek (struct queue *pq) {
    if (!isEmpty(&q)) 
        cout << "\nTop Element  : " << pq->item[pq->rear];
    else
        cout << "\nQueue is Empty !!";
}

void display (struct queue *pq) {
    if (!isEmpty(&q)) {
        cout << "\nQueue : ";
        for (int i = pq->front+1; i <= pq->rear; i++)
            cout << pq->item[i] << " ";
    }
    else
        cout << "\nQueue is Empty !!";
}

int main() {
    int option,insert_value,removed_value;
    char choose;
    q.front = -1;
    q.rear = -1;
    do {
        system("cls");
        cout << "\n********************";
        cout << "\n\tQUEUE";
        cout << "\n********************";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice : ";
        cin >> option;
        
        switch(option) {
            case 1: if (!isFull(&q)) {
                        cout << "\nEnter a new element : ";
                        cin >> insert_value;
                        enqueue(&q,insert_value);
                    }
                    else
                        cout << "\nQueue is Full !!";
                break;
            
            case 2: removed_value = dequeue(&q);
                    if (!isEmpty(&q))
                        cout << "\nDeleted Element : " << removed_value;
                break;

            case 3: peek (&q);
                break;
            
            case 4: display (&q);
                break;
            
            case 5: cout << "\nExitting !!";
                    exit(0);
                break;
            
            default : cout << "\nWarning : Please enter a valid option !!";
        }
        cout << "\nDo you want to continue (Y|N) : ";
        cin >> choose;
    } while(choose == 'y' || choose =='Y');
    return 0;
} 
