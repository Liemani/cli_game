/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:46:59 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/03 15:06:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>	// struct time
#include "time.h"
#include <lmt_c_library.h>	// TRUE, FALSE

///	- description: result must differ with lhs or rhs
///	- parameters:
///		- lhs: non-optional
///		- rhs: non-optional
///		- result: non-optional
void	time_add(const t_time *lhs,
		const t_time *rhs, t_time *result)
{
	result->tv_sec = lhs->tv_sec + rhs->tv_sec;
	result->tv_usec = lhs->tv_usec + rhs->tv_usec;
	if (result->tv_usec > SEC_IN_USEC)
	{
		++result->tv_sec;
		result->tv_usec -= SEC_IN_USEC;
	}
}

///	- description: result must differ with lhs or rhs
///	- parameters:
///		- lhs: non-optional
///		- rhs: non-optional
///		- result: non-optional
void	time_subtract(const t_time *lhs,
		const t_time *rhs, t_time *result)
{
	result->tv_sec = lhs->tv_sec - rhs->tv_sec;
	result->tv_usec = lhs->tv_usec - rhs->tv_usec;
	if (result->tv_usec < 0)
	{
		--result->tv_sec;
		result->tv_usec += SEC_IN_USEC;
	}
}

///	- parameters:
///		- lhs: non-optional
///		- rhs: non-optional
int		time_gt(const t_time *lhs, const t_time *rhs)
{
	if (lhs->tv_sec > rhs->tv_sec)
		return (TRUE);
	else if (lhs->tv_sec == rhs->tv_sec)
		return (lhs->tv_usec > rhs->tv_usec);
	return (FALSE);
}
