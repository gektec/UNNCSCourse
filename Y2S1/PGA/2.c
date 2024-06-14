#include <stdio.h>
int a, b;

int enter(){
    printf("please enter two numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    return 0;
}

int main(){
    int n, stop;
    stop = 0;
    while (stop == 0){
        printf("Enter 1 to add 2 numbers;\nEnter 2 to multiply 2 numbers;\nEnter 3 to and calculate the modulus of 2 numbers;\nEnter 4 to exit the program.\n");
        scanf("%d", &n);
        switch (n){
        case 1:
            enter();
            printf("the sum is %d.\n", a + b);
            break;
        case 2:
            enter();
            printf("the product is %d.\n", a * b);
            break;
        case 3:
            enter();
            int c;
            if (a < b) c = b % a;
            else c = a % b;
            printf("the modulus is %d.\n", c);
            break;
        case 4:
            stop = 1;
            break;
        default:
            printf("invalid input, please enter again.\n");
            break;
        }
    }
}
