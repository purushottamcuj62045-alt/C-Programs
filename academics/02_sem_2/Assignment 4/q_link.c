#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Queue
{
    node *front;
    node *rear;
} queue;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

int isEmpty(queue *q)
{
    return q->front == NULL;
}

void enqueue(queue *q, int data)
{
    node *newNode = createNode(data);
    if (!newNode)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

void printQueue(queue *q)
{
    node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value;
    queue *q = createQueue();

    do
    {
        printf("\n1. Insertion  2. Deletion  3. Display 0 Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of  value you want to add\n: ");
            int n;
            scanf("%d",&n);
            for(int i=0; i<n;i++)
            {
            printf("Enter Value:-");
            scanf("%d", &value);
            enqueue(q, value);
            }
            break;

        case 2:
        printf("\nenter the number of elements you want to delete:-");
        int k;
        scanf("%d",&k);
        for(int i =0; i<k; i+++)
        {
            value = dequeue(q);
            if (value != -1)
                printf("Deleted: %d\n", value);
        }
            break;

        case 3:
            printQueue(q);
            break;
        case 0:
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
