#include <stdio.h>	// perror()
#include <stdlib.h>	// exit(), NULL
#include <unistd.h>	// write(), usleep()
#include "display.h"
#include "lmt_c_library.h"	// ERROR
#include "time.h"

void	display_draw(t_display *display)
{
	lmt_write(1, "\033[8A\033[0G");
	if (write(1, display->buffer, (display->width + 1) * display->height - 1) == -1)
	{
		perror(NULL);
		exit(ERROR);
	}
}

void	display_fill_ch(t_display *display, char ch)
{
	const char	*last_element = display->buffer + ((display->width + 1) * display->height - 1);
	char		*element;
	int			column;

	if (ch == '\n')
		return ;
	element = display->buffer;
	while (element <= last_element)
	{
		column = 0;
		while (column < display->width)
		{
			*element = ch;
			++element;
			++column;
		}
		++element;
	}
}
