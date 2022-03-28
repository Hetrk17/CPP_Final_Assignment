#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int fds[2];

void main()
{
	int res,i;
	pid_t p;
	res = pipe(fds);
	char *buf1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *buf2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	char buf[100];
	int n;
	if(res == -1)
	{
		perror("pipe");
		exit(1);
	}
	p = fork();
	if(p==0)
	{
		
		close(fds[0]);
		write(fds[1],buf1,20);
		write(fds[1],buf2,20);
		printf("End of perent\n");
	}
	else
	{
		close(fds[1]);
		n = read(fds[0],buf,40);
		printf(" no of chars read = %d\n",n);
		for(i=0;i<n;i++)
		{
			if(buf[i]>='a' && buf[i]<= 'z')
			buf[i] = buf[i] -32;			
		}
		for(i=0;i<n;i++)
		{
			printf("%c", buf[i]);
		}
		printf("\n");
	}
	
	wait(0);
	printf("End of progream\n");
}
