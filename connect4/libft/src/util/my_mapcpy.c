/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/30 02:27:07 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

int	my_mapcpy(char *dst[], char *src[], size_t size)
{
	size_t	i;

	if (src == NULL || dst == NULL)
		return (EINVAL);
	i = 0;
	while (i < size)
	{
		if (src[i])
		{
			dst[i] = my_strdup(src[i]);
			if (!dst[i])
				return (errno);
		}
		else
			dst[i] = NULL;
		i++;
	}
}
