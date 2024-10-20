/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:50:00 by alphbarr          #+#    #+#             */
/*   Updated: 2024/10/20 19:50:57 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	char		*line;
	t_tokens	*tokens;
	int			i;

	while (1)
	{
		// Leer la entrada del usuario
		line = readline("minishell> ");
		if (!line)  // Si el usuario introduce Ctrl-D, salir del shell
			break ;
		// Tokenizar la entrada del usuario
		tokens = tokenize_input(line);
		if (!tokens)
		{
			free(line);
			continue;  // Si falla la tokenización, se continúa con la siguiente entrada
		}
		// Imprimir los tokens
		printf("Tokens:\n");
		i = 0;
		while (i <tokens->count)
		{
			printf("[%s]\n", tokens->tokens[i]);
			i++;
		}
		// Imprimir la primera variable de entorno como ejemplo
		if (env[0])
			printf("First env variable: %s\n", env[0]);
		free_tokens(tokens);
		free(line);
	}
	return (0);
}
