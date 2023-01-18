/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:55:50 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/13 07:57:36 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		ii;

	if (!s1 || !s2)
		return (0);
	r = (char *) ft_calloc(1, ft_strlen((char *) s1) + ft_strlen((char *)s2) + 1);
	if (!r)
		return (0);
	i = 0;
	ii = 0;
	while (s1[i])
		r[ii++] = s1[i++];
	i = 0;
	while (s2[i])
		r[ii++] = s2[i++];
	r[ii] = 0;
	return (r);
}
