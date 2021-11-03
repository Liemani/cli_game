#include <stdio.h>	// EOF
#include <stdlib.h>	// free()
#include <unistd.h>	// sleep()
#include <sys/time.h>	// gettimeofday()
#include "game.h"
#include "display.h"
#include "character.h"
#include "lmt_c_library.h"	// TRUE

void	game_free(t_game *game)
{
	display_free(game->display);
	character_free(game->character);
	free(game);
}

static void	game_set_display(t_game *game)
{
	int					position_index;
	static t_character	*character;

	character = game->character;
	switch (game->input)
	{
		case 'w':
			character->face = NORTH;
			if (character->position.y > 0)
				character->position.y -= 1;
			break ;
		case 'a':
			character->face = WEST;
			if (character->position.x > 0)
				character->position.x -= 2;
			break ;
		case 's':
			character->face = SOUTH;
			if (character->position.y < game->display->height - 1)
				character->position.y += 1;
			break ;
		case 'd':
			character->face = EAST;
			if (character->position.x < game->display->width - 2)
				character->position.x += 2;
			break ;
		default:
			break ;
	}
	game->input = EOF;
	display_fill_ch(game->display, '`');
	position_index = (game->display->width + 1) * character->position.y + character->position.x;
	game->display->buffer[position_index] = *character->appearance[character->face];
	game->display->buffer[position_index + 1] = *(character->appearance[character->face] + 1);
}

static void	game_sleep(t_game *game)
{
	t_time	interval;
	t_time	target_time;
	t_time	current_time;
	t_time	time_to_sleep;

	time_init(&interval, 0, SEC_IN_USEC / TARGET_FPS);
	time_add(&game->time_last_draw, &interval, &target_time);
	gettimeofday(&current_time, NULL);
	time_subtract(&target_time, &current_time, &time_to_sleep);
	if (time_to_sleep.tv_sec == 0)
		usleep(time_to_sleep.tv_usec);
	gettimeofday(&game->time_last_draw, NULL);
}

void	game_loop(t_game *game)
{
	while (TRUE)
	{
		game_sleep(game);
		game->input = getchar();
		game_set_display(game);
		display_draw(game->display);
	}
}
