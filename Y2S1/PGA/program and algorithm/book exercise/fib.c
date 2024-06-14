#include<stdio.h>

int fib(int num);

int main(){
    int test;
    test = fib(10);
    printf("%d",test);
}

int fib(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    return fib(num-1)+fib(num-2);
}