#include <stdio.h>

int main(void){
	int n[5]= {1};
	for (int i = 0; i < 5; ++i) {
	printf("%7u%13d\n", i, n[i]);
	}
}