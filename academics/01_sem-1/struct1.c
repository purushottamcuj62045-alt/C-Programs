#include<stdio.h>

struct mystructure
{
    int mynum;
    char myletter;
};

int main()
{
    struct mystructure s1;
    struct mystructure s2;


    s1.mynum = 13;
    s1.myletter = 'c';


    s2.mynum = 25;
    s2.myletter = 'z';

    printf("s1 number: %d\n", s1.mynum);
    printf("s1 letter: %c\n", s1.myletter);

    printf("s2 number: %d\n", s2.mynum);
    printf("s2 letter: %c\n", s2.myletter);

    return 0;
}
 