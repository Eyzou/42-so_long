/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elo <elo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:07:01 by ehamm             #+#    #+#             */
/*   Updated: 2024/05/18 10:39:39 by elo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*s;
	char	ac;

	len = ft_strlen(str);
	s = (char *)str;
	ac = c;
	if (ac == '\0')
		return (s + len);
	while (len--)
	{
		if (ac == str[len])
			return (s + len);
	}
	return (NULL);
}

/*int main (void)
{
    char str[9] = "Bonjourj";
    printf("%s\n", ft_strrchr(str,'o'));
}*/
