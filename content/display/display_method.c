#include <stdlib.h>	// exit()
#include <unistd.h>	// write(), usleep()
#include <sys/time.h>	// gettimeofday()
#include "display.h"
#include "lmt_c_library.h"	// ERROR
#include "time.h"

void	display_draw(t_display *display)
{
	t_time	interval;
	t_time	target_time;
	t_time	current_time;
	t_time	time_to_sleep;

	time_init(&interval, 0, SEC_IN_USEC / TARGET_FPS);
	time_add(&display->time_last_draw, &interval, &target_time);
	gettimeofday(&current_time, NULL);
	time_subtract(&target_time, &current_time, &time_to_sleep);
	if (time_to_sleep.tv_sec == 0)
		usleep(time_to_sleep.tv_usec);
	gettimeofday(&display->time_last_draw, NULL);
	if (write(1, display->buffer, (display->width + 1) * display->height) == -1)
		exit(ERROR);
	lmt_write(1, "\033[10A\033[0G");
}

void	display_fill_ch(t_display *display, char ch)
{
	const char	*last_element = display->buffer + ((display->width + 1) * display->height - 1);
	char		*element;

	element = display->buffer;
	while (element <= last_element)
	{
		if (*element != '\n')
			*element = ch;
		++element;
	}
}
