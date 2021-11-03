#ifndef CHARACTER_H
# define CHARACTER_H

# include "vector2.h"

# define NORTH	0
# define EAST	1
# define WEST	2
# define SOUTH	3

typedef struct s_character
{
	char		*appearance[4];
	t_vector2	position;
	int			face;
}	t_character;

t_character	*character_new(void);
void		character_free(t_character *character);

#endif
