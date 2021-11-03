#include <stdlib.h>	// free()
#include "game.h"
#include "lmt_c_library.h"	// lmt_alloc()
#include "display.h"

static t_game	*game_alloc(void)
{
	return (malloc(sizeof(t_game)));
}

static void	game_init(t_game *game)
{
	game->input = '\0';
	game->display = display_new(DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

t_game	*game_new(void)
{
	t_game	*game;

	game = game_alloc();
	game_init(game);
	return (game);
}

void	game_free(t_game *game)
{
	display_free(game->display);
	free(game);
}
