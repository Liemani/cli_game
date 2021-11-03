#ifndef DISPLAY_H
# define DISPLAY_H

# include "time.h"

# define TARGET_FPS	60

///	- description:
///		buffer size is (width + 1) * height
///		buffer is filled with data to draw screen including '\n'
///		don't fill another index of buffer with '\n'
typedef struct s_display
{
	int		width;
	int		height;
	char	*buffer;
	t_time	time_last_draw;
}	t_display;

///	- type
t_display	*display_new(int width, int height);
void		display_free(t_display *display);

///	- method
void	display_draw(t_display *display);
void	display_fill_ch(t_display *display, char ch);

#endif
