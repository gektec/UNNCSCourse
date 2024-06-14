#include<stdio.h>
#include<string.h>

//pefect number 

void isPerfect(int num);

int main(){
	for (int i=1;i<=100000;i++){
		isPerfect(i);
	}
}

void isPerfect(int num){
	int sum=0;
	for (int i=1;i<num;i++){
		if (num%i==0){
			sum=sum+i;
		} 
	}
	if (sum==num){
		printf("%d=1",num);
		for (int i=2;i<num;i++){
			if (num%i==0){
				printf("*%d",i);
			} 
		}
		puts(""); 
	}
}

