#include<stdio.h>

int fibi(int num);

int main(){
    int test;
    test = fibi(10);
    printf("%d",test);
}

int fibi(int num){
    int cur=0;
    int next=1;
    for (int i=0;i<num;i++){
        int temp=next+cur;
        cur=next;
        next=temp;
    }
    return cur;
}