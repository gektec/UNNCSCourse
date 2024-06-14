#include<stdio.h>
#include<string.h>

// p387 function strcspn just pay attention to the initial

int main(void){
	const char *str1="The value is .314159";
	const char *str2="1234567890";
	const char *str3="The value is 3.14159";

	printf("%s%s\n%s%s\n\n%s\n%s%u\n",
		"str1=",str1,"str2=",str2,
		"The length of the intial length of string 1",
		"containing no characters from str2 = ",
		strcspn(str1,str2)
		);
	printf("%s%s\n%s%s\n\n%s\n%s%u\n",
		"str3=",str3,"str2=",str2,
		"The length of the intial length of string 3",
		"containing no characters from str2 = ",
		strcspn(str3,str2)
		);
}