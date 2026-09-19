#include<stdio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;
int item[size];
int isFull() {
    return rear == size - 1;
}
int isEmpty() {
    return front == -1;
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    item[rear] = value;
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    else{
        printf("Deleted element: %d\n", item[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
}
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", item[i]);
    }
    printf("\n");
}
int main() {
    int choice, value;
    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}