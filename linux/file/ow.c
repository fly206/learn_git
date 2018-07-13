#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#define BUFFER_SIZE 1024
#define SRC_FILE_NAME "src_file"
#define DEST_FILE "dest_file"
#define OFFSET 10240

int main(int argc, char *argv[]) {
	int src_file, dest_file;
	unsigned char buff[BUFFER_SIZE];
	int real_read_len;
	struct timeval tv;
	long starttime,endtime;
	gettimeofday(&tv, NULL);
	starttime = tv.tv_usec;
	if(argc != 3) {
		printf("arguments error\n");
		exit(1);
	}
	src_file = open(argv[1], O_RDONLY);
	dest_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if(src_file<0 || dest_file<0) {
		printf("Open file error\n");
		exit(1);
	}
	lseek(src_file, -OFFSET, SEEK_END);
	while((real_read_len = read(src_file, buff, sizeof(buff))) > 0) {
		write(dest_file, buff, real_read_len);
	}
	close(dest_file);
	close(src_file);
	gettimeofday(&tv,NULL);
	endtime=tv.tv_usec;
	printf("Running time: %u us.\n",endtime-starttime);
	return 0;
}

