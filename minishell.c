/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:34:50 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/10/12 18:57:02 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	while (1)
	{
		readline("minishell>");
		if (!line)
			break ;
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
