#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node *createNode(int val) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val; n->left = n->right = NULL; return n;
}

struct Node *insert(struct Node *root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

void inorder(struct Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(struct Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

void display(struct Node *r, int space) {
    if (!r) return;
    space += 5;
    display(r->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d", r->data);
    display(r->left, space);
}

int main() {
    struct Node *root = NULL;
    int ch, val, n;
    while (1) {
        printf("\n1.Insert Single  2.Insert Multiple  3.Inorder  4.Preorder  5.Postorder  6.Display  7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2: printf("How many: "); scanf("%d", &n);
                    for (int i = 0; i < n; i++) { printf("Node %d: ", i+1); scanf("%d", &val); root = insert(root, val); } break;
            case 3: inorder(root); printf("\n"); break;
            case 4: preorder(root); printf("\n"); break;
            case 5: postorder(root); printf("\n"); break;
            case 6: display(root, 0); printf("\n"); break;
            case 7: exit(0);
            default: printf("Invalid!\n");
        }
    }
}