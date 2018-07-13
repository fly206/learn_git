/************recursion.c***************
 * one usage of typedef
 * share library test
 *
 * ***********************************/

void recursion(int n) {
	printf("before:n=%d\n",n);
	if(n > 1) {
		recursion(n-1);
	} else {
		printf("end:n=%d\n",n);
	}
	printf("after:n=%d\n",n);
}


