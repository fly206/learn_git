/*********************ccp.c*************************
 * P.21 2018.07.01
 * c language for "cp"
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc,char *argv[]) {
	FILE *fds,*fdt;
	char answer = -1;
	ssize_t size = -1;
	char buf[1024];
	struct timeval tv;
	long starttime,endtime;
	gettimeofday(&tv,NULL);
	starttime=tv.tv_usec;
	if(argc != 3) {
		printf("Usage:%s SOURCE TARGET.\n", argv[0]);
		return 1;
	}
	fds = fopen(argv[1],"rb");
	if(NULL == fds) {
		printf("%s: The source doesn't exist.\n",argv[0]);
		return 2;
	}
	fclose(fds);
	fdt = fopen(argv[2],"wb+");
	if(NULL == fdt) {
		printf("%s: Overwrite '%s'?",argv[0],argv[2]);
		scanf("%c",&answer);
		if(answer != 'y') {
			return 3;
		}
		else {
			fdt = fopen(argv[2],"wb+");
		}
	}
	fds = fopen(argv[1], "rb");
	if(NULL == fds) {
		printf("%s: %s open error.\n",argv[0],argv[1]);
		return 4;
	}
	while(size) {
		size = fread(buf, sizeof(char),1024,fds);
		if(size == -1) {
			printf("%s: %s read error.\n",argv[0],argv[1]);
			return 5;
		}
		else {
			if(size > 0) {
				fwrite(buf,sizeof(char),size,fdt);
			}
		}
	}
	fclose(fdt);
	fclose(fds);
	gettimeofday(&tv,NULL);
	endtime=tv.tv_usec;
	printf("Running time: %u us.\n",endtime-starttime);
	return 0;
}


