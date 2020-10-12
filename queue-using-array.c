#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear;
    unsigned length;
    int* array;
};

struct Queue* createQueue(unsigned length)
{
    struct Queue* queue = (struct Queue*) malloc (sizeof(struct Queue));
    queue->length = length;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*) malloc (sizeof(int) * queue->length);
    printf("\n-> Queue of size %d is created!\n",queue->length);
    return queue;
}

int isFull(struct Queue* queue)
{
    return queue->rear == queue->length - 1;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == -1 || queue->front > queue->rear;
}

void push(struct Queue* queue)
{
    int var;
    if(isFull(queue))
    {
        printf("\n-> Queue is full!\n");
        return;
    }
    if(isEmpty(queue))
    {
        queue->front += 1;
    }
    printf("\n-> Enter the element : ");
    scanf("%d", &var);
    queue->rear += 1;
    queue->array[queue->rear] = var;
    printf("\n-> %d element is pushed in the queue\n", var);
}

int pop(struct Queue* queue)
{
    int var;
    if(isEmpty(queue))
    {
        printf("\n-> Queue is empty!\n");
        return -1;
    }
    var = queue->array[queue->front];
    queue->front += 1;
    printf("\n-> %d element is popped out of the queue\n", var);
    return var;
}

int peek(struct Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("\n-> Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->rear];
}

int main()
{
    int var;
    unsigned length,choice;

    printf("-> Enter size of Queue : ");
    scanf("%d", &length);
    struct Queue* queue = createQueue(length);
    while(1)
    {
        printf("\n->Enter your choice :");
        printf("\n1. Insert element");
        printf("\n2. Delete element");
        printf("\n3. Check if queue is full");
        printf("\n4. Check if queue is empty");
        printf("\n5. Get rear element");
        printf("\n6. Exit");
        printf("\n\n-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: push(queue);
            break;

        case 2: var = pop(queue);
            break;

        case 3: var = isFull(queue);
            printf("\n-> %s\n", var ? "True" : "False");
            break;

        case 4: var = isEmpty(queue);
            printf("\n-> %s\n", var ? "True" : "False");
            break;

        case 5: var = peek(queue);
            printf("\n-> %d\n", var);
            break;

        case 6: free(queue);
            exit(0);

        default: printf("\n-> Invalid Choice! Please try again.\n");
            break;
        }
    }
    return 0;
}
