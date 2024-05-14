#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

int main()
{
	int pid,ret,sig;

	printf("Entre the process id: ");
	scanf("%d",&pid);

	printf("Entre the signal number: ");
	scanf("%d",&sig);

	ret=kill(pid, sig);

	if(ret == 0)
		printf("Signal sent successfully \n");
	else
		printf("Signal sending failed\n");
	if(ret == -1)
		perror("kill");

	return 0;
}
