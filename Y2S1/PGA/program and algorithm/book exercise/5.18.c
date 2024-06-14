#include <stdio.h>

int Even();

int main(){
    int test;
    test=Even();
    printf("%d",test);
}

int Even()
{
    int num;
    scanf("%d",&num);
    if (num%2==0)
        return 1;
    else
        return 0;
}