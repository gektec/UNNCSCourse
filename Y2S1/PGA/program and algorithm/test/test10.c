#include <string.h>
#include <stdio.h>
int main()
{
char s1[] = "Fun with Coding";
char s2[] = "Coding";
char* p;
p = strstr(s1, s2);
if (p) {
strcpy(p, "Strings");
printf("%s\n", s1);
printf("%s",p);
} else
printf("String not found\n");
return 0;
}