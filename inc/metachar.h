/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metachar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:05:30 by alphbarr          #+#    #+#             */
/*   Updated: 2024/10/20 20:13:09 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METACHARACTERS_H
# define METACHARACTERS_H

// Metacaracteres usados para la tokenización
# define META_CHARS "|<>;$"

// Metacaracteres individuales para más control
# define PIPE '|'
# define REDIR_IN '<'
# define REDIR_OUT '>'
# define REDIR_APPEND_OUT ">>"
# define HEREDOC "<<"
# define SEMICOLON ';'
# define DOLLAR '$'

// Definición de comillas
# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '"'

// Definir las variables de entorno y su expansión
# define VAR_ENVIRONMENT '$'
# define VAR_STATUS "$?"

#endif

