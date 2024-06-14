#include <stdio.h>

int main() 
{ 
    int number, i;

    printf("Enter number of values: ");
    scanf("%d", &number);

    if (number<=0){
        printf("Invalid array length!");
        return 0;
    }

    int array[number];

    for(i=0; i<number; i++){
        printf("Enter position %d value: ", i);
        scanf("%d", &array[i]);
        if (array[i]%2!=0)
            i--;
    }

    for(i=0; i<number; i++){
        if (array[i]>0)
            printf("%d\n", array[i]);
    }

    return 0;
}