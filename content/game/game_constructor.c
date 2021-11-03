#include <stdio.h>	// EOF
#include <signal.h>	// signal()
#include <stdlib.h>	// malloc()
#include <fcntl.h>	// fcntl()
#include <termios.h>	// tcgetattr(), tcsetattr()
#include "game.h"
#include "display.h"
#include "character.h"

static t_game	*game_alloc(void)
{
	return (malloc(sizeof(t_game)));
}

static void	game_init_stdin(void)
{
	int	flag;

	flag = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, (flag | O_NONBLOCK | O_ASYNC));
}

static void	game_init_termios(void)
{
	struct termios	termios;

	tcgetattr(0, &termios);
	termios.c_lflag &= ~ICANON;
	termios.c_lflag &= ~ECHO;
	tcsetattr(0, TCSAFLUSH, &termios);
}

static void	nothing(int signal)
{
	(void)signal;
}

static void	game_init(t_game *game)
{
	signal(SIGIO, nothing);
	game_init_stdin();
	game_init_termios();
	game->input = EOF;
	game->display = display_new(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	game->character = character_new();
}

t_game	*game_new(void)
{
	t_game	*game;

	game = game_alloc();
	game_init(game);
	return (game);
}
