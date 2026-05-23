/*<------------------Implementation of queue using array-------------------> */
#include <stdio.h>
#define MAX_SIZE 100

//==================Define a structure for the queue==========================
struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

//================Function to initialize the queue==============================
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

//================Function to check if the queue is empty========================
int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

//===============Function to check if the queue is full===========================
int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

//=================Function to insert an element into the queue===================
void inqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = data;
    printf("%d in inserted in queue\n", data);
}

//======================Function to remove an element from the queue====================
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->queue[q->front];
    //=====================If the queue is empty reset the pointers======================
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Deleted element: %d\n", data);
    return data;
}

//==============Function to display the elements of the queue=============================
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
//----------------------------------Initialize a queue-----------------------------------------
    struct Queue q;
    initializeQueue(&q);
    int n,s,l;
   char add;

do {
    printf("Enter your choice\n");
    printf("1. Insertion        2. Deletion      3.Display\n");
    printf("Your choice:- ");
    scanf("%d",&l);

    switch(l){
        case 1:{
            printf("Number of data you want to add:");
            scanf("%d",&n);
            for(int i =0;i<n;i++)
            {
                printf("Enter Data !");
                int p;
                scanf("%d",&p);
                inqueue(&q, p);
            }
            printf("Elements in the queue after enqueue operation: ");
            display(&q);
            break;
        }

        case 2:{
            printf("Enter the number of element you want to delete");
            scanf("%d",&s);
            for(int i=0; i<s;i++)
            {
                dequeue(&q);
            }
            break;
        }
        case 3:{
                display(&q);
                break ;
        }

        default:
            printf("Invalid choice\n");
    }
    printf("Do you want to run the program again (y/n): ");
    scanf(" %c", &add);

} while (add == 'y' || add == 'Y');
    return 0;
}