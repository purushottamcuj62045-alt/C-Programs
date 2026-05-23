#include<stdio.h>
struct student
{
    int id;
    char name[30];
    float marks;
};
int main()
{
    struct student s1={1,"luffy",13.40};
    struct student s2={2,"zoro",14.69};
    printf("id= %d\n",s1.id);
    printf("id= %s\n",s1.name);
    printf("id= %f\n",s1.marks);
    printf("id= %d\n",s2.id);
    printf("id= %s\n",s2.name);
    printf("id= %f\n",s2.marks);
    return 0;
}