#include<stdio.h>
#include<stdlib.h>

int main()
{
	{
		#define _A_
		int a=15;
		printf("%d\n", a);
	}
	int a=16;
#ifdef _A_ 
	printf("%d\n", a);
#else
	printf("no valument\n");
#endif
	return 0;
}

