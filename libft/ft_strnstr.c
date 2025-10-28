/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:45:48 by Camille           #+#    #+#             */
/*   Updated: 2025/10/27 15:19:46 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	
	if (!little[0])
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len && big[i] && little[j])
	{
		if (big[i] == little[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (!little[j])
		return ((char *)big + i - j);
	return (NULL);
}
/*#include <stdio.h>
#include <bsd/bsd.h>
int	main(void)
{
	char *s1 = "see FF your FF return FF now FF";
 	char *s2 = "FF";
 	size_t max = -1;
	//size_t max = ft_strlen(s1);

	printf("strnstr:%s\nft:%s", strnstr(s1, s2, max), ft_strnstr(s1, s2, max));

	return (0);
}*/
