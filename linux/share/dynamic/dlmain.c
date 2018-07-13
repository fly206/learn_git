#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {
	void *pHandle;
	void (*pFunc)();
	int *p;
	if(argc!=2) {
		printf("Parmeter Error!\n");
		exit(1);
	}
	pHandle = dlopen(argv[1], RTLD_NOW);
	if(!pHandle) {
		printf("Can't find %s\n", argv[1]);
		exit(1);
	}
	pFunc = (void(*)())dlsym(pHandle,"print");
	if(pFunc)
		pFunc();
	else
		printf("Can't find function print\n");
	p = (int *)dlsym(pHandle,"p");
	if(p)
		printf("p = %d\n", *p);
	else
		printf("Can't find int p\n");
	dlclose(pHandle);
	return 0;
}

