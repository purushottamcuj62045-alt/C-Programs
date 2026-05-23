/* write a menue driven program to perform the following operation on one way link list.
1.creation of ink list 
2.traversing the element of link list.
3.insertion at begning
4.insertion at end
5.finding location of given element 
6.insertion after a given node
7.insertion after a given element 
8.deletion of the first node
9.deletion of the last node
10.deletion of a given element */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function Prototypes */
void create();
void traverse();
void insert_begin();
void insert_end();
void find_location();
void insert_after_node();
void insert_after_element();
void delete_first();
void delete_last();
void delete_element();

int main() {
    int choice;
    char add;

    do {
        printf("\n\n===== MENU =====\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Find Location of Element\n");
        printf("6. Insert After Given Node (Position)\n");
        printf("7. Insert After Given Element\n");
        printf("8. Delete First Node\n");
        printf("9. Delete Last Node\n");
        printf("10. Delete Given Element\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  create();               break;
            case 2:  traverse();             break;
            case 3:  insert_begin();         break;
            case 4:  insert_end();           break;
            case 5:  find_location();        break;
            case 6:  insert_after_node();    break;
            case 7:  insert_after_element(); break;
            case 8:  delete_first();         break;
            case 9:  delete_last();          break;
            case 10: delete_element();       break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default: printf("Invalid Choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &add);

    } while (add == 'y' || add == 'Y');

    printf("Goodbye!\n");
    return 0;
}

void create() {
    int n, i, value;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = NULL;

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

void traverse() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_begin() {
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Inserted at beginning.\n");
}

void insert_end() {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Inserted at end.\n");
}

void find_location() {
    int key, pos = 1;
    struct node *temp = head;

    printf("Enter element to find: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found.\n");
}

void insert_after_node() {
    int pos, i;
    struct node *temp = head;
    struct node *newnode = malloc(sizeof(struct node));

    printf("Enter position: ");
    scanf("%d", &pos);

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted successfully.\n");
}

void insert_after_element() {
    int key;
    struct node *temp = head;
    struct node *newnode = malloc(sizeof(struct node));

    printf("Enter element after which to insert: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found.\n");
        free(newnode);
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted successfully.\n");
}

void delete_first() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}

void delete_last() {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }

    printf("Last node deleted.\n");
}

void delete_element() {
    int key;
    struct node *temp = head, *prev = NULL;

    printf("Enter element to delete: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Element deleted.\n");
}