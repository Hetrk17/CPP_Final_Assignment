#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fds[2];

void main()
{
	int res,i;
	int p[2];
	pipe(p);
	res = pipe(fds);
	char s[20];
	char buf[100];
	int n;
	if(fork())
	{
		
		
		printf("In perent write data:- ");
		scanf("%s", s); 
		write(p[1],s, strlen(s)+1);
		printf("End of perent\n");
	}
	else
	{
		
		printf("In the child.........");
		n = read(p[0],buf,100);
		printf("Child proc printing Data of the prent process %s\n",buf);
		printf("\n");
	}
	
	wait(0);
	printf("End of progream\n");
}
