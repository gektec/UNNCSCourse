#include<stdio.h>

int * sort(int *a,int size);

void printfa(int *a, int size);

int main(){
	int a[]={3,5,2,8,7};
	sort(a,5);
	printfa(a,5);
}

int * sort(int *a,int size){
	int temp;
	for (int i=0;i<size-1;i++){
		for(int j=0;j<size-1;j++){
			if (a[j]>a[j+1]){
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	return a;
}

void printfa(int *a,int size){
	for(int i=0;i<size;i++){
		printf("%d\n",a[i]);
	}
}