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
	size_t	size;
	
	i = 0;
	j = 0;
	size = ft_strlen(little) - 1;
	if (!little)
		return ((char *)big);
	if (size > len)
		size = len;
	while (big[i])
	{
		if (big[i] == little[j])
		{
			if (j == size)
				return (&((char *)big)[i-j]);
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int	main(void)
{
	char * big = "TRUC";
	char * little = "RU";

	printf("%s", ft_strnstr(big, little, ft_strlen(little)));

	return (0);
}*/
