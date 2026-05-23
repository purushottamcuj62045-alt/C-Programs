#include<stdio.h>
int main()
{

struct my_structure
{
    char name[50];
    int age;
    float power;
};
 
struct my_structure b={"Luffy",18,1900};
struct my_structure c;
  c=b;

  //we have swaped the values

  printf("Structure c\n");
  printf("My_structure name %s\n",c.name);
  printf("My_structure age %d \n",c.age);
  printf("My_structure power%1f",c.power);
  return 0;
}