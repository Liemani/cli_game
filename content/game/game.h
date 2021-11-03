#ifndef GAME_H
# define GAME_H

# include "display.h"

# define DISPLAY_WIDTH	80
# define DISPLAY_HEIGHT	10

typedef struct s_game
{
	int			input;
	t_display	*display;
}	t_game;

t_game	*game_new(void);
void	game_free(t_game *game);

#endif
