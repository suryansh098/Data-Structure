#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty()
{
    return front == NULL;
}

void push()
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    int var;
    printf("\n-> Enter the element : ");
    scanf("%d", &var);
    temp->data = var;
    temp->next = NULL;
    if (isEmpty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    printf("\n-> %d element is pushed in the queue\n", var);
}

int pop()
{
    int var;
    struct Node* temp;
    if(isEmpty())
    {
        printf("\n-> queue is empty!\n");
        return -1;
    }
    var = front->data;
    temp = front;
    front = front->next;
    free(temp);
    printf("\n-> %d element is popped out of the queue\n", var);
    return var;
}

int peek()
{
    if(isEmpty())
    {
        printf("\n-> queue is empty!\n");
        return -1;
    }
    return rear->data;
}

void display()
{
    struct Node* p=front;

    if(isEmpty())
    {
        printf("\n-> queue is empty!\n");
        return;
    }

    printf("\n-> ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void free_memory()
{
    struct Node* p;
    while(front!=NULL)
    {
        p = front->next;
        free(front);
        front = p;
    }
}

int main()
{
    int var;
    unsigned choice;

    while(1)
    {
        printf("\n->Enter your choice :");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. isEmpty");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\n\n-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: push();
            break;

        case 2: var = pop();
            break;

        case 3: var = peek();
            printf("\n-> %d\n", var);
            break;

        case 4: var = isEmpty();
            printf("\n-> %s\n", var ? "True" : "False");
            break;

        case 5: display();
            break;

        case 6: free_memory();
            exit(0);

        default: printf("\n-> Invalid Choice! Please try again.\n");
            break;
        }
    }
    return 0;
}

