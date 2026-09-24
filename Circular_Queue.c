#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
int isFull()
{
    if ((front == (rear + 1) % SIZE) || (front == 0 && rear == SIZE - 1))
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (front == -1)
    {

        return 1;
    }
    return 0;
}
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Enqueued element: %d\n", value);
}
int dequeue()
{
    int element;

    if (isEmpty())
    {
        printf("Queue underflow\n");
        return -1;
    }

    else
    {
        element = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        return element;
    }
}
int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("Front element: %d\n", value);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}