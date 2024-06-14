
/* 
 * Program: Tower of Hanoi
 * Author : Abhishek Kadariya [0501]
 * BATCH OF 2019 DWIT
 * 
 * Ref    : Data structures using C and C++, Chap 2.
*/
#include<stdio.h>
#include<conio.h>


void procedure( int, char, char, char);

int main(){
    int n; 
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    procedure(n, 'A', 'C', 'B');
    return 0;
}


void procedure(int n, char source, char destination, char reference){
   
   if(n==1){
   printf("Move disc 1 from %c to %c\n",source,destination);
   return;
   }
   
   procedure(n - 1,source, reference, destination);
   printf("Move disk %d from %c to %c\n", n, source, destination);
   procedure(n- 1, reference, destination, source);
}

















/*
Iterative Algorithm: 

1. Calculate the total number of moves required i.e. "pow(2, n)
   - 1" here n is number of disks.
2. If number of disks (i.e. n) is even then interchange destination 
   pole and auxiliary pole.
3. for i = 1 to total number of moves:
     if i%3 == 1:
    legal movement of top disk between source pole and 
        destination pole
     if i%3 == 2:
    legal movement top disk between source pole and 
        auxiliary pole    
     if i%3 == 0:
        legal movement top disk between auxiliary pole 
        and destination pole 
*/