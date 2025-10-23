/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:01:16 by Camille           #+#    #+#             */
/*   Updated: 2025/10/22 19:11:14 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcpy(void *dest, const void *src, size_t n)
{
	while(n)
	{
		n--;
		(unsigned const char) dest[n] = (unsigned const char) src[n];
	}
	return (dest);
}
