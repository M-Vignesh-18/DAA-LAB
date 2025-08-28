#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->arr[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

void display(Stack* stack) {
	int i;
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for ( i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element is %d\n", peek(&stack));

    printf("Popped element is %d\n", pop(&stack));

    display(&stack);

    return 0;
}
