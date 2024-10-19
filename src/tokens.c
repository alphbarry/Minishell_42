#include "../inc/minishell.h"

void	free_tokens(t_tokens *tokens)
{
	int	i;

	if (tokens)
	{
		i = 0;
		while (i < tokens->count)
		{
			free(tokens->tokens[i]);
			i++;
		}
		free(tokens->tokens);
	}
	free(tokens);
}

char ft_tokenizer(char *str, char *delim)
{
    static char *static_str = NULL; // Mantiene la posición en la cadena entre llamadas
    if (str != NULL)
        static_str = str;
    if (static_str == NULL)
        return NULL;
    // Saltar delimitadores iniciales
    static_str += strspn(static_str, delim);
    if (*static_str == '\0')
        return NULL;
    // Encontrar el final del token
    char *token_start = static_str;
    static_str = strpbrk(token_start, delim);
    if (static_str != NULL)
    {
        *static_str = '\0';
        static_str++;
    }
    else
        static_str = token_start + strlen(token_start);
    return token_start;
}

t_tokens	*tokenize_input(char *input)
{
	t_tokens	*res;
	char		*input_copy;
	char		*token;
	char		**new_tokens;

	res = (t_tokens)malloc(sizeif(t_tokens));
	if (!res)
		return(NULL);
	res->count = 0;
	res->tokens = NULL;
	input_copy = ft_strdup(input);
	if (!input_copy)
	{
		free(res);
		return NULL;
	}
	token = ft_tokenizer(input_copy, " ");
	while (token)
	{
		new_tokens = (char **)realloc(res->tokens, sizeof(char *) * (res->count + 1));
		if (!new_tokens)
		{
			free_tokens(res);
			return NULL;
		}
		res->tokens[res->count] = ft_strdup(tokens);
		if (res->tokens[res->count])
		{
			free_tokens(res);
			return NULL;
		}
		res->count++;
		token = ft_tokenizer(NULL, " ");
	}
	return(res);
}

int main()
{
    t_input input;
    input.tmp_cmd = "echo Hello World";

    char *token = ft_tokenizer(input.tmp_cmd, " ");
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = ft_tokenizer(NULL, " ");
    }
    return 0;
}
