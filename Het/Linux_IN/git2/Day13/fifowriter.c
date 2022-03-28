#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main()
{
	char s[20];
	int fd;
	
	mkfifo("newfifo1",644);
	
	perror("mkfifo");
	
	printf("Befour open() ....\n");
	fd = open("newfifo11", O_WRONLY);
	printf("After open()......");
	
	printf("Enter data........\n");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
}
