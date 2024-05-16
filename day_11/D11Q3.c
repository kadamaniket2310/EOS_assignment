#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int arr[2];

void sigint_handler(int sig){
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}

int main()
{
	char ch ='A';
	int ret;
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = pipe(arr);
	sigaction(SIGINT, &sa, NULL);

	int count = 0;
	while(1)
	{
		write(arr[1], &ch, 1);
		count++;
		printf("Bytes written: %d\n",count);
	}
}
