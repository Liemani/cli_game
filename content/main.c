#include <stdlib.h>	// malloc()
#include <pthread.h>	// pthread_t, pthread_create()
#include <unistd.h>	// sleep(), pause()
#include <stdio.h>	// scanf(), printf()
#include <sys/time.h>	// gettimeofday(), struct time
#include <termios.h>	//
#include "lmt_c_library.h"	// TRUE, NORMAL
#include "game.h"

void	*thread_routine_input(void *game)
{
	struct termios	termios;

	tcgetattr(0, &termios);
	termios.c_lflag &= ~ICANON;
	termios.c_lflag &= ~ECHO;
	tcsetattr(0, TCSAFLUSH, &termios);
	while ((((t_game *)game)->input = getchar()) != EOF);
	return (NULL);
}

void	*thread_routine_display(void *game)
{
	while (TRUE)
	{
		if (((t_game *)game)->input != '\0')
			display_fill_ch(((t_game *)game)->display, ((t_game *)game)->input);
		display_draw(((t_game *)game)->display);
	}
	return (NULL);
}

int main()
{
	t_game		*game;
	pthread_t	thread_input;
	pthread_t	thread_display;

	game = game_new();
	pthread_create(&thread_input, NULL, thread_routine_input, game);
	pthread_create(&thread_display, NULL, thread_routine_display, game);
	while (TRUE)
		pause();
	return (NORMAL);
}
