#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int fds[2];

void perent_code()
{
	char *buf1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *buf = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	//close(fds[0]);
	write(fds[1],buf1,20);
	write(fds[1],buf,20);
	printf("End of perent\n");
	
}
void child_code()
{
	char buf[100];
	int n,i;
	//close(fds[1]);
	n = read(fds[0],buf,40);
	printf(" no of chars read = %d\n",n);
	for(i=0;i<n;i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");
}
void main()
{
	int res,i;
	pid_t p;
	res = pipe(fds);
	if(res == -1)
	{
		perror("pipe");
		exit(1);
	}
	p = fork();
	if(p==0)
	{
		child_code();
	}
	else
	{
		perent_code();
	}
	
	wait(0);
	printf("End of progream\n");
}
