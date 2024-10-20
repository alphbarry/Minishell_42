/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:59 by alphbarr          #+#    #+#             */
/*   Updated: 2024/10/20 20:14:01 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/src/libft.h"
# include "./metachar.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/

typedef enum e_bool
{
	false,
	true
}	e_bool;

/* Entrada del usuario */
typedef struct s_input
{
	int				size_prompt;//Es para saber cuantos caracteres ocupa el prompt actual. Es util para controlar la interfaz, mover el cursor, o manejar el historial de comandos correctamente.
	e_bool			history_flag;//Si history es true, significa que el comando actual que se esta ejecutando o procesando ha sido recuperado del historial de comandos (usando las teclas de flecha hacia arriba o hacia abajo, por ejemplo). Si es false, el comando se ingreso por primera vez.
	char			*tmp_cmd;//Se usa para almacenar una entrada temporal mientras se procesa el comando actual. Por ejemplo, podría ser usado durante la edicion de la linea de comandos o mientras se manipulan y validan los datos antes de pasarlos al sistema para ejecutar.
	char			*exec_cmd;//Aquí se almacena el comando final en el shell. Después de la edición y procesamiento, esta cadena contiene el comando que será tokenizado, parseado y eventualmente ejecutado.
}	t_input;

/* Historial de comandos */
typedef struct s_cmd_history
{
	int						index;//indica el número de orden o posición del comando dentro del historial. Esto es util para recorrer el historial hacia adelante o hacia atras.
	char					*input_cmd;//Aquí se guarda la linea de comando completa que se ha ingresado.
	struct s_cmd_history	*prev_cmd;//Facilita el recorrido hacia atras en el historial, de manera que se puede revisar comandos anteriores al actual
	struct s_cmd_history	*next_cmd;//Este permite avanzar hacia el siguiente comando en el historial, útil cuando se esta revisando comandos mas recientes.
}	t_cmd_history;

/* MINISHELL */
typedef struct s_shell
{
	// t_dict					*env_vars;// Almacena las variables de entorno que estarAn disponibles para los comandos que ejecute la shell.
	struct termios			term_backup;//Almacena la configuración de terminal antes de que la shell realice modificaciones
	t_input					cmd_input;//Gestiona la linea de comandos activa, la longitud del prompt, y si el comando proviene o no del historial
	t_cmd_history			*cmd_history;//Almacena el primer comando en la lista del historial. Permite navegar y manipular el historial de comandos ingresados anteriormente
	t_cmd_history			*curr_hist;//Apunta al nodo del historial actual, lo que facilita la navegacion por el historial cuando se utilizan las teclas de dirección para revisar comandos anteriores o recientes
}	t_shell;


/* TOKENS */

t_tokens	*tokenize_input(char *input);
