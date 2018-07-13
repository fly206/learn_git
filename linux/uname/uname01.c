/**************uname.c**********************
 * function to get system information
 *  P.11 (2018.07.01)
 ******************************************/

#include<stdio.h>
#include<sys/utsname.h>

int main(void)
{
	struct utsname sysinfo;
	uname(&sysinfo);
	printf("Sysname: %s\n", sysinfo.sysname);
	printf("nodename:%s\n", sysinfo.nodename);
	printf("Release: %s\n", sysinfo.release);
	printf("Version: %s\n", sysinfo.version);
	printf("Machine: %s\n", sysinfo.machine);
	return 0;
}

