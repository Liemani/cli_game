#include <stdlib.h>	// free()
#include "vector2.h"
#include "lmt_c_library.h"	// lmt_alloc()

static t_vector2	*vector2_alloc(void)
{
	return (malloc(sizeof(t_vector2)));
}

void	vector2_init(t_vector2 *vector2, int x, int y)
{
	vector2->x = x;
	vector2->y = y;
}

t_vector2	*vector2_new(int x, int y)
{
	t_vector2	*vector2;

	vector2 = vector2_alloc();
	vector2_init(vector2, x, y);
	return (vector2);
}

void	vector2_free(t_vector2 *vector2)
{
	free(vector2);
}
