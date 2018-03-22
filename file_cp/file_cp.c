#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/time.h>

int main(int argc,char *argv[]) {
    int fds = -1;
    int fdt = -1;
    char answer = 'n';
    ssize_t size = -1;
    char buf[1024];
    struct timeval tv;
    long starttime,endtime;
    gettimeofday(&tv,NULL);
    starttime=tv.tv_usec;
    if(argc != 3) {
        printf("Usage: %s SOURCE TARGET.\n",argv[0]);
        return 1;
    }
    fds = open(argv[1], O_RDONLY | O_EXCL);
    if(fds == -1) {
        printf("%s: The source doesn't exist.\n",argv[0]);
        return 2;
    }
    close(fds);
    fdt = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 00666);
    if(fdt == -1) {
        printf("%s: Overwrite '%s' ?",argv[0],argv[2]);
        scanf("%c",&answer);
        if(answer != 'y') {
            return 3;
        }
        else {
            fdt = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 00666);
        }
    }
    fds = open(argv[1], O_RDONLY);
    if(fds == -1) {
        printf("%s: %s open error.\n",argv[0],argv[1]);
        return 4;
    }
    while(size) {
        size = read(fds,buf,1024);
        if(size == -1) {
            printf("%s: %s read error.\n",argv[0],argv[1]);
            return 5;
        }
        else {
            if(size > 0) {
                write(fdt,buf,size);
            }
        }
    }
    close(fdt);
    close(fdt);
    gettimeofday(&tv,NULL);
    endtime=tv.tv_usec;
    printf("Running time: %u us.\n",endtime-starttime);
    return 0;
}

