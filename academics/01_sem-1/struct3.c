#include<stdio.h>
struct car
{
  char brand[30];
  char model[40];
  int year;
};
int main(){
    struct car c1={"Bmw","x5",999};
    struct car c2={"food","mustard",589};
    struct car c3={"luffy","olx",8690};
    printf("Car1 %s %s  %d\n",c1.brand,c1.model,c1.year);
    printf("car2 %s %s %d\n",c2.brand,c2.model,c2.year);
    printf("car3 %s %s %d\n",c3.brand,c3.model,c3.year);
    return 0;

}