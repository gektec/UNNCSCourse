#include<stdio.h>

int main(void){
    int arr1[10];
    int arr2[10];
    int arr3[20];
    int value;
    int p=0;
    for (int i=0; i<10; i++){
        printf("Please enter 10 numbers for arr1: " );
        scanf("%d",&value);
        arr1[i]=value;
    }
    for (int i=0; i<10; i++){
        printf("Please enter 10 numbers for arr2: " );
        scanf("%d",&value);
        arr2[i]=value;
    }
    for (int i=0; i<10; i++){
        for (int k=0;k<10;k++){
            if (arr1[i]==arr2[k]){
                arr3[p]=arr1[i];
                p++;
                break;
            }
        }
    }
    for (int i=0;i<p;i++){
        printf("%d ", arr3[i]);
    }
     if (p==0)
        return 0;   
}