#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student{
    int rollNo;
    char name[60];
    char course[40];
    float marks;
};
int main() 
{
    int n, i, searchRoll;
    int topIndex = 0;
    float totalMarks = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student *s = (struct Student *)malloc(n * sizeof(struct Student));// Allocate memory dynamically

    if (s == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < n; i++) 
    {
    //<---------Accept student details---------->
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf(" %[^\n]s", s[i].name);

        printf("Course: ");
        scanf(" %[^\n]s", s[i].course);

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        totalMarks += s[i].marks;

        if (s[i].marks > s[topIndex].marks) 
        {
            topIndex = i;
        }
    }
    printf("\n\n------ Student Details ------\n");
    printf("%-10s %-20s %-15s %-10s\n", "RollNo", "Name", "Course", "Marks");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-10d %-20s %-15s %-10.2f\n",
               s[i].rollNo, s[i].name, s[i].course, s[i].marks);
    }
    printf("\n\nStudent with Highest Marks:\n");
    printf("Roll No: %d\n", s[topIndex].rollNo);
    printf("Name    : %s\n", s[topIndex].name);
    printf("Course  : %s\n", s[topIndex].course);
    printf("Marks   : %.2f\n", s[topIndex].marks);
    printf("\nEnter roll number to search: ");
    scanf("%d", &searchRoll);
    // <-----------Search student by roll number-------------->
    int found = 0;
    for (i = 0; i < n; i++) 
    {
        if (s[i].rollNo == searchRoll) 
        {
            printf("\nStudent Found!\n");
            printf("Roll No: %d\n", s[i].rollNo);
            printf("Name    : %s\n", s[i].name);
            printf("Course  : %s\n", s[i].course);
            printf("Marks   : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) 
    {
        printf("\nStudent with roll number %d not found.\n", searchRoll);
    }
    float avg = totalMarks / n;//<----Average marks---->
    printf("\nAverage Marks of Class = %.2f\n", avg);
    free(s);// <----Free allocated memory---->

    return 0;
}