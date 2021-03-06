/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 09:25:01 by cleticia          #+#    #+#             */
/*   Updated: 2021/07/26 06:14:48 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = -1;
	if (nb == 0)
		return (0);
	while (++i < nb)
	{
		if ((i * i) == nb)
		return (i);
	}
	return (0);
}
