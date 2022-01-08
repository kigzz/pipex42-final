/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:24:55 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:24:56 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *src)
{
	char	*cp;
	size_t	len;

	len = ft_strlen(src) + 1;
	cp = (char *)malloc(sizeof(char) * len);
	if (!cp)
		return (NULL);
	ft_memcpy(cp, src, len);
	return (cp);
}
