/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:25:04 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:25:18 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		end;

	i = 0;
	end = 0;
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
		end = i;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dest[end] = s2[i];
		i++;
		end++;
	}
	dest[end] = '\0';
	return (dest);
}
