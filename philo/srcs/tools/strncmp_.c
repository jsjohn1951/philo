/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:32:08 by wismith           #+#    #+#             */
/*   Updated: 2022/08/06 14:32:28 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *) s1;
	str2 = (char *) s2;
	if (n == 0)
		return (0);
	while (*str1 && *str2 && *str1 == *str2 && n > 0)
	{
		str1++;
		str2++;
		n--;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
