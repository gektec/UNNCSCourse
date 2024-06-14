#include<stdio.h>

int max_array(int array[],int length);

int main(){
    int test;
    int a[3]={3,6,5};
    test=max_array(a,3);
    printf("%d",test);
}

int max_array(int array[],int length){
    int max = array[0];
    int i;
    for (i=0;i<length-1;i++){
        if (max<array[i]){
            max=array[i];
        }
           
    }
    return max;
}


