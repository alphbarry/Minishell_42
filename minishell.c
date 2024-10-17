/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:34:50 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/10/17 19:05:43 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av, char **env)
{
	char	*line;

	while (1)
	{
		readline("minishell>");
		if (!line)
			break ;
		printf("%s\n", line);
		printf("%s\n", env[0]);
		free(line);
	}
	return (0);
}
