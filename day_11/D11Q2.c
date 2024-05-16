#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int arr1[3],arr2[3],ret;
	int a,b,res,s;
	ret = pipe(arr1);
	ret = pipe(arr2);
	ret = fork();
	if(ret == 0)
	{
		close(arr1[0]);
		close(arr2[1]);
		printf("Entre two numbers:\n");
		scanf("%d %d",&a,&b);
		write(arr1[1], &a, sizeof(a));
		write(arr1[1], &b, sizeof(b));

		read(arr2[0], &res, sizeof(res));
		printf("result : %d\n",res);

		close(arr2[0]);
		close(arr1[1]);
	}
	else
	{
		close(arr1[1]);
		close(arr2[0]);
		read(arr1[0], &a, sizeof(a));
		read(arr1[0], &b, sizeof(b));

		res = a + b;
		printf("sender result : %d\n",res);
		write(arr2[1], &res, sizeof(res));
		close(arr2[1]);
		close(arr1[0]);
		waitpid(-1, &s, 0);
	}
}
