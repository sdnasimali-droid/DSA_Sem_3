#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
}
void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}
int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}
int main() {
    int choice, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
