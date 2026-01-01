/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salalawn <salalawn@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:54:56 by salalawn          #+#    #+#             */
/*   Updated: 2025/12/13 14:54:58 by salalawn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*alts;
	char	altc;
	int		i;

	alts = (char *)s;
	altc = (char)c;
	i = ft_strlen(alts);
	while (i >= 0)
	{
		if (alts[i] == altc)
			return (alts + i);
		i--;
	}
	return (NULL);
}
