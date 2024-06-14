#include<stdio.h>

int main(){
	int c;
	if ((c=getchar())!=EOF){
		//exchange line7 and 8
		printf("%c",c);
		main();
	}
}