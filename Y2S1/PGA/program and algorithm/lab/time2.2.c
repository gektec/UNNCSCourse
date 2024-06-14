//20320370 scyyd4 Yi Ding

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int remove_value(int *values, int len, int x);

int main(void){
	int len;
	printf("Enter number of values: ");
	scanf("%d",&len);
	if(len<=0){
		printf("Invalid array length!\n");
		return 0;
	}
	int arr[len];
	for (int i=0;i<len;i++){
		printf("Enter position %d value: ", i);
		scanf("%d",&arr[i]);
	}
	printf("Enter value to remove: ");
	int x;
	scanf("%d",&x);
	int y;
	y=remove_value(arr,len,x);
	printf("Number of values after removal is %d\n",y);
	for (int j=0;j<y;j++){
		printf("%d\n",arr[j]);
	}
	return 0;
}

int remove_value(int *values, int len, int x){
	int i=0;
	int final=len;
	while(i<final){
		if (values[i]==x){
			final--;
			for (int j=i;j<=final;j++){
				values[j]=values[j+1];
			} 
		}
		else
			i++;		
	}
	return final; 
}