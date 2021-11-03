#include <stdlib.h>	// free()
#include "display.h"
#include "lmt_c_library.h"	// lmt_alloc()

static t_display	*display_alloc(void)
{
	return (malloc(sizeof(t_display)));
}

void	display_buffer_init(t_display *display)
{
	char	*last_of_row;
	int		row;

	display->buffer = malloc(sizeof(char *) * ((display->width + 1) * display->height - 1));
	last_of_row = display->buffer + display->width;
	row = 1;
	while (row < display->height)
	{
		*last_of_row = '\n';
		last_of_row += (display->width + 1);
		++row;
	}
}

static void	display_init(t_display *display, int width, int height)
{
	display->width = width;
	display->height = height;
	display_buffer_init(display);
	display_fill_ch(display, '`');
	lmt_write(1, "\n\n\n\n\n\n\n\n");
}

t_display	*display_new(int width, int height)
{
	t_display	*display;

	display = display_alloc();
	display_init(display, width, height);
	return (display);
}

void	display_free(t_display *display)
{
	free(display->buffer);
	free(display);
}
