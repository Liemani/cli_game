#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	*thread_run(void *_)
{
	(void)_;
	while (1)
	{
		sleep(1);
		printf("redrawing \n");
	}
	return (NULL);
}

int main()
{
	pthread_t	thread;
	int			return_value;
	char		*line;

	line = malloc(20);
	pthread_create(&thread, NULL, thread_run, NULL);
	while (1)
	{
		return_value = scanf("%s", line);
		printf("line -> [%s], return_value -> [%d] \n", line, return_value);
	}
	return (0);
}
