#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "students.txt"
typedef struct {
    int rollNumber;
    char name[21]; 
    char course[11]; 
    float marks;
} Student;
void createNewFile();
void displayAllRecords();
void appendRecord();
void modifyRecord();
void recreateAndRead();
void viewAndAdd();
void inputStudentData(Student *s);
void printHeader();
void printRow(Student s);
int main() {
    int choice;
    do {
        printf("\n========= Student Record Management System =========\n");
        printf("1. Create new record file (w mode)\n");
        printf("2. Display all student records (r mode)\n");
        printf("3. Append new student record (a mode)\n");
        printf("4. Modify existing record (r+ mode)\n");
        printf("5. Recreate and read records (w+ mode)\n");
        printf("6. View and add records (a+ mode)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch(choice) {
            case 1: createNewFile(); 
            break;
            case 2: displayAllRecords(); 
            break;
            case 3: appendRecord(); 
            break;
            case 4: modifyRecord(); 
            break;
            case 5: recreateAndRead();
            break;
            case 6: viewAndAdd(); 
            break;
            case 7: printf("Exiting program...\n"); 
            break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}
void inputStudentData(Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNumber);
    while(getchar() != '\n'); 
    printf("Enter Name (Single word/Underscores): ");
    scanf("%20s", s->name); 
    while(getchar() != '\n'); 
    printf("Enter Course: ");
    scanf("%10s", s->course);
    while(getchar() != '\n');
    printf("Enter Marks: ");
    scanf("%f", &s->marks);
    while(getchar() != '\n');
}
void printHeader() {
    printf("\n----------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-6s\n", "Roll", "Name", "Course", "Marks");
    printf("----------------------------------------------------\n");
}
void printRow(Student s) {
    printf("%-5d %-20s %-10s %-6.2f\n", s.rollNumber, s.name, s.course, s.marks);
}
void createNewFile() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    int n, i;
    Student s;
    printf("\nWARNING: Existing data will be deleted.\n");
    printf("How many students do you want to add? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        inputStudentData(&s);
        fprintf(fp, "%-5d %-20s %-10s %6.2f\n", s.rollNumber, s.name, s.course, s.marks);
    }
    printf("File created and records saved successfully.\n");
    fclose(fp);
}
void displayAllRecords() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No data found. Please create a file first.\n");
        return;
    }
    Student s;
    printHeader();
    while (fscanf(fp, "%d %20s %10s %f", &s.rollNumber, s.name, s.course, &s.marks) != EOF) {
        printRow(s);
    }
    fclose(fp);
}
void appendRecord() {
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("\nAdding New Record:\n");
    inputStudentData(&s);
    fprintf(fp, "%-5d %-20s %-10s %6.2f\n", s.rollNumber, s.name, s.course, s.marks);
    printf("Record appended successfully.\n");
    fclose(fp);
}
void modifyRecord() {
    FILE *fp = fopen(FILENAME, "r+");
    if (fp == NULL) {
        printf("No data found. Please create a file first.\n");
        return;
    }
    int targetRoll, found = 0;
    Student s;
    long int pos;
    printf("Enter Roll Number to modify: ");
    scanf("%d", &targetRoll);
    while (!feof(fp)) {
        pos = ftell(fp);
        if (fscanf(fp, "%d %20s %10s %f", &s.rollNumber, s.name, s.course, &s.marks) == EOF) break;
        if (s.rollNumber == targetRoll) {
            found = 1;
            printf("\nRecord Found:\n");
            printRow(s);
            printf("\nEnter New Details:\n");
            inputStudentData(&s);
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%-5d %-20s %-10s %6.2f\n", s.rollNumber, s.name, s.course, s.marks);
            printf("Record updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Record with Roll Number %d not found.\n", targetRoll);
    }
    fclose(fp);
}
void recreateAndRead() {
    FILE *fp = fopen(FILENAME, "w+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int n, i;
    Student s;
    printf("\n(w+ Mode) Clearing file and entering new data...\n");
    printf("How many students? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        inputStudentData(&s);
        fprintf(fp, "%-5d %-20s %-10s %6.2f\n", s.rollNumber, s.name, s.course, s.marks);
    }
    rewind(fp);
    printf("\n--- Data currently in file (Read verification) ---\n");
    printHeader();
    while (fscanf(fp, "%d %20s %10s %f", &s.rollNumber, s.name, s.course, &s.marks) != EOF) {
        printRow(s);
    }
    fclose(fp);
}
void viewAndAdd() {
    FILE *fp = fopen(FILENAME, "a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("\n--- Current Records ---\n");
    rewind(fp);
    printHeader();
    while (fscanf(fp, "%d %20s %10s %f", &s.rollNumber, s.name, s.course, &s.marks) != EOF) {
        printRow(s);
    }
    printf("\n--- Append New Record ---\n");
    inputStudentData(&s);
    fprintf(fp, "%-5d %-20s %-10s %6.2f\n", s.rollNumber, s.name, s.course, s.marks);
    printf("\n--- Updated List ---\n");
    rewind(fp);
    printHeader();
    while (fscanf(fp, "%d %20s %10s %f", &s.rollNumber, s.name, s.course, &s.marks) != EOF) {
        printRow(s);
    }
    fclose(fp);
}