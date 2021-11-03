#include <stdlib.h>	// free(), malloc()
#include "character.h"

static t_character	*character_alloc(void)
{
	return (malloc(sizeof(t_character)));
}

static void	character_init(t_character *character)
{
	character->appearance[NORTH] = "ii";
	character->appearance[EAST] = "iI";
	character->appearance[WEST] = "Ii";
	character->appearance[SOUTH] = "II";
	vector2_init(&character->position, 40, 4);
	character->face = SOUTH;
}

t_character	*character_new(void)
{
	t_character	*character;

	character = character_alloc();
	character_init(character);
	return (character);
}

void	character_free(t_character *character)
{
	free(character);
}
