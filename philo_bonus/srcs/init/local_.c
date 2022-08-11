/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:38:06 by wismith           #+#    #+#             */
/*   Updated: 2022/08/10 15:41:53 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	local_vars_(t_data *data, t_philo *p)
{
	p->local.td_ = data->td_;
	p->local.te_ = data->te_;
	p->local.ts_ = data->ts_;
	p->local.np_ = data->np_;
	p->local.me_ = data->me_;
	p->local.must_eat = data->must_eat;
}
