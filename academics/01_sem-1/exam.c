#include <stdio.h>
int numCount(int random[]){
    int random[13];
    int count=0;
    for(int i=0;i<=12;i++){
    if(random[i]==7){
        count++;
    }
    }
return count;
}

int main(){
    int r[]={1,7,3,4,3,7,5,5,4,7,7,5,9};
    int p;
    p= numCount(r);
   printf("Count of 7 is %d",p);
    return 0;
}