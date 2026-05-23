#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int main()
{
int n, i, value;
struct node *newnode, *temp;
printf("Enter number of nodes:");
scanf("%d",&n);
head = 0;
for (i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    printf("List Created Successfully!\n");
}

