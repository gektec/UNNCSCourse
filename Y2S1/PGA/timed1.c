//20513997 scycl11 Changyu Li
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	printf("Enter number of values: ");
	int n;
	cin>>n;
	if (n <= 0)
	{
		printf("Invalid array length!\n");
		exit(0);
	}
	int a[n], i, t = 0;
	for (i = 0; i < n; i++)
	{
		while (t == 0)
		{
			printf("Enter position %d value: ", i);
			scanf("%d", &a[i]);
			if (a[i] % 2 == 0)
				t = 1;
		}
		t = 0;
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
			printf("%d\n", a[i]);
	}
}