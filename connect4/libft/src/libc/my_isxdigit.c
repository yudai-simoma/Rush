/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:14:38 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/30 02:04:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

int	my_isxdigit(int c)
{
	return (('0' <= c && c <= '9') || ('a' <= c && c <= 'f'));
}