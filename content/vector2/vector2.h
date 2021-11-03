#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

t_vector2	*vector2_new(int x, int y);
void		vector2_free(t_vector2 *vector2);

#endif
