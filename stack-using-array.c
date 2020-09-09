#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned length;
    int* array;
};

struct Stack* createStack(unsigned length)
{
    struct Stack* stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack->length = length;
    stack->top = -1;
    stack->array = (int*) malloc (sizeof(int) * stack->length);
    printf("\n-> Stack of size %d is created!\n",stack->length);
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->length - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack)
{
    int var;
    if(isFull(stack))
    {
        printf("\n-> Stack is full!\n");
        return;
    }
    printf("\n-> Enter the element : ");
    scanf("%d", &var);
    stack->top += 1;
    stack->array[stack->top] = var;
    printf("\n-> %d element is pushed in the stack\n", var);
}

int pop(struct Stack* stack)
{
    int var;
    if(isEmpty(stack))
    {
        printf("\n-> Stack is empty!\n");
        return -1;
    }
    var = stack->array[stack->top];
    stack->top -= 1;
    printf("\n-> %d element is poped out of the stack\n", var);
    return var;
}

int peek(struct Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("\n-> Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top];
}

int main()
{
    int var;
    unsigned length,choice;

    printf("-> Enter size of stack : ");
    scanf("%d", &length);
    struct Stack* stack = createStack(length);
    while(1)
    {
        printf("\n->Enter your choice :");
        printf("\n1. Insert element");
        printf("\n2. Delete element");
        printf("\n3. Check if stack is full");
        printf("\n4. Check if stack is empty");
        printf("\n5. Get top element");
        printf("\n6. Exit");
        printf("\n\n-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: push(stack);
            break;

        case 2: var = pop(stack);
            break;

        case 3: var = isFull(stack);
            printf("\n-> %s\n", var ? "True" : "False");
            break;

        case 4: var = isEmpty(stack);
            printf("\n-> %s\n", var ? "True" : "False");
            break;

        case 5: var = peek(stack);
            printf("\n-> %d\n", var);
            break;

        case 6: free(stack);
            exit(0);

        default: printf("\n-> Invalid Choice! Please try again.\n");
            break;
        }
    }
    return 0;
}
