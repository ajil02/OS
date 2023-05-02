#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>

void main()
{
	struct stat sfile;
	stat("lab1_3.c",&sfile);
	printf("st_size=%ld\n",sfile.st_size);
}
