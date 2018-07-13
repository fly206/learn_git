#include <fcntl.h>		//open()函数
#include <sys/types.h>		//mode_t类型
#include <sys/stat.h>		//open()函数的符号
#include <unistd.h>		//close()函数
#include <stdio.h>		//标准输入输出函数

int main() {
	int f;
	const char *f_path = "test.txt";
	mode_t f_attrib;
	f_attrib = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH;
	f = open(f_path, O_RDONLY);
	if(f ==-1) {
		f = open(f_path, O_RDWR | O_CREAT, f_attrib);
		if(f != -1)
			puts("Created a new file.");
		else {
			puts("Can't create the new file.");
			return 1;
		}
	}
	else {
		puts("Open file success.");
	}
	close(f);
	return 0;
}

