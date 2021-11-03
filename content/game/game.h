#ifndef GAME_H
# define GAME_H

# include "display.h"
# include "character.h"

# define DISPLAY_WIDTH	80
# define DISPLAY_HEIGHT	9

typedef struct s_game
{
	int			input;
	t_display	*display;
	t_character	*character;
	t_time		time_last_draw;
}	t_game;

t_game	*game_new(void);
void	game_free(t_game *game);

void	game_loop(t_game *game);

#endif
