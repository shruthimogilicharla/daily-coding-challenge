#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Deque Overflow\n");
    else {
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = MAX - 1;
        else
            front--;
        deque[front] = value;
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Deque Overflow\n");
    else {
        if (front == -1)
            front = rear = 0;
        else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
        deque[rear] = value;
    }
}

void deleteFront() {
    if (front == -1)
        printf("Deque Underflow\n");
    else {
        printf("Deleted: %d\n", deque[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

void deleteRear() {
    if (front == -1)
        printf("Deque Underflow\n");
    else {
        printf("Deleted: %d\n", deque[rear]);
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }

    int i = front;
    printf("Deque: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}
