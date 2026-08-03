#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top Element: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    return 0;
}
