#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


int full_array(int a, int b, int array[]);

int main(void){
	int a,b;
	int arr[101];
	

	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter b: ");
	scanf("%d",&b);
	full_array(a,b,arr);
	while (full_array(a,b,arr)==-1){
		printf("Impossible\n");
		printf("Enter a: ");
		scanf("%d",&a);
		printf("Enter b: ");
		scanf("%d",&b); 
	}
	printf("Array created:");
	for (int i=0;i<b-a+1;i++){
		printf(" %d",arr[i]);
	}
	
}

int full_array(int a, int b, int array[]){
	if (a<0||b<0||a>=b||b>100)
		return -1;
	for (int i=0;i<b-a+1;i++){
			array[i]=i+a;
		}
	
	return 0;
}


