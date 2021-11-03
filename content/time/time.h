/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:47:06 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/03 15:04:28 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>	// struct time

//	struct timeval
//	{
//		time_t		tv_sec;
//		suseconds_t	tv_usec;
//	}
//	typedef long	time_t
//	typedef int		suseconds_t
typedef struct timeval	t_time;

# define SEC_IN_USEC	1000000
# define USEC_LEN		6

///	- type
int		time_parse(t_time *time, char *time_str);
void	time_init(t_time *time, long sec, int usec);

///	- method
void	time_add(const t_time *lhs, const t_time *rhs,
			t_time *result);
void	time_subtract(const t_time *lhs,
			const t_time *rhs, t_time *result);
int		time_gt(const t_time *lhs,
			const t_time *rhs);

#endif
