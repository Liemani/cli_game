/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:42:12 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/03 14:26:53 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc()
#include <sys/time.h>	// struct time
#include "time.h"
#include "lmt_c_library.h"

int	time_parse(t_time *time, char *time_str)
{
	char			*sec_str;
	char			*usec_str;

	if (time_str == NULL)
		time_str = "0";
	sec_str = time_str;
	usec_str = time_str;
	while (lmt_is_digit(*usec_str))
		++usec_str;
	if (*usec_str != '\0')
		return (PARSE_FAILURE);
	if (usec_str - USEC_LEN < sec_str)
		usec_str = sec_str;
	else
		usec_str -= USEC_LEN;
	if (lmt_atoi(usec_str, &time->tv_usec) != PARSE_SUCCESS)
		return (PARSE_FAILURE);
	*usec_str = '\0';
	if (sec_str == usec_str)
		time->tv_sec = 0;
	else
		if (lmt_atol(sec_str, &time->tv_sec) != PARSE_SUCCESS)
			return (PARSE_FAILURE);
	return (PARSE_SUCCESS);
}

void	time_init(t_time *time, long sec, int usec)
{
	time->tv_sec = sec;
	time->tv_usec = usec;
}
