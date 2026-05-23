#include<stdio.h>
struct mystructure{
    int num;
    char mylletter;
};
int main()
{
struct mystructure s1;
s1.num=199;
s1.mylletter='b';
printf("my number:%d\n",s1.num);
printf("my letter %c\n",s1.mylletter);
return 0;  
}