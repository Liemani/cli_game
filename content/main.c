#include <stdio.h>	// scanf(), printf()
#include <sys/time.h>	// gettimeofday(), struct time
#include <termios.h>	//
#include "lmt_c_library.h"	// TRUE, NORMAL
#include "game.h"

int main(void)
{
	t_game		*game;

	game = game_new();
	game_loop(game);
	game_free(game);
	return (NORMAL);
}
