#include <stdio.h>
union st {
	int i;
	char c[2];
};

int main() {
	union st x;
	x.c[0] = 3;
	x.i = 0;
	x.c[1] = 10;
	printf("%d\n", x.i);
	printf("%d\n", x.c[0]);
	printf("%d\n", x.c[1]);
	printf("x.i[1] = %d\n", *((&x.i)+1));
	printf("&x.c[0] = %d\n", &x.c[0]);
	printf("&x.c[0] +sizechar = %d\n", &x.c[0]+sizeof(char));
	printf("&x.c[1] = %d\n", &x.c[1]);
	printf("&x.i + sizechar = %d\n", &x.i+sizeof(char));
	printf("&x.i + sizeint = %d\n", &x.i+sizeof(int));
	printf("&x.i[1] = %d\n", &((&x.i)[1]));
	printf("&x.i = %d\n", &x.i);
	printf("%d %d %d\n",sizeof(union st),sizeof(int),sizeof(char));
	return 0;
}

