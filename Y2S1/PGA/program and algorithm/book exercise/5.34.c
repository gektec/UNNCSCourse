#include <stdio.h>

int r_exp(int num);

int main(){
    int test;
    test=r_exp(5);
    printf("%d",test);
}

int r_exp(int num){
    if (num==1)
        return 1;
    else 
        return r_exp(num-1)*num;
}