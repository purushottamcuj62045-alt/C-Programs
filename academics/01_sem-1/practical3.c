#include <stdio.h>
#include <stdlib.h>

void addBook() {
    FILE *fp = fopen("library.txt", "a");
    if (fp == NULL) {
        printf("Error! ha  \n");
        return;
    }

    int id;
    char title[100], author[100];
    float price;

    printf("Enter Book ID:");
    scanf("%d", &id);

    printf("Enter Book Title: ");
    getchar(); 
    fgets(title, sizeof(title), stdin);

    
    for (int i = 0; title[i]; i++)
        if (title[i] == '\n') title[i] = '\0';
     
    printf("Enter Author Name: "); 
  
    fgets(author, sizeof(author), stdin);


    for (int i = 0; author[i]; i++)
        if (author[i] == '\n') author[i] = '\0';
     
    printf("Enter Price: ");
    scanf("%f", &price);

   

    fprintf(fp, "%d\t||\t%s\t||\t%s\t||\t%.2f\n", id, title, author, price);
    fclose(fp);

    printf("Record added ho gya!\n");
}

void displayBooks() {
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL) {
        printf( " File does not exist.\n");
        return;
    }

    printf("\n--- Displaying All Books ---\n");

    char ch;
    printf("id   \t   title  \t  author  \t  price\n");
    while ((ch=fgetc(fp))!=EOF) {
        putchar(ch);
    }

    fclose(fp);
}

void createBackup() {
    FILE *org = fopen("library.txt", "r");
    FILE *copy = fopen("backup.txt", "w");
    

    if (org == NULL) {
        printf("Error! Source file not found.\n");
        return;
    }
    if (copy == NULL) {
        printf("Error! Could not create backup file.\n");
        fclose(org);
        return;
    }

    char ch;
    while ((ch = fgetc(org)) != EOF){
        fputc(ch, copy);
        putchar(ch);
    }
    
    fclose(org);
    fclose(copy);
    

    printf("Backup create ha  \n");
}

int main() {
    int choice;

    while (1) {
        printf("\n***** Library Record System *****\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Create Backup\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: createBackup(); break;
            case 4: 
                printf("exit ho gya ...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}