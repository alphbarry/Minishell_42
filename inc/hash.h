#ifndef HASH_H
# define HASH_H

# include "./libft/src/libft.h"

typedef struct s_node
{
	char			*key;
	void			*value;
	struct s_node	*next;
}	t_node;

typedef struct e_hash
{
	t_node			**array;
	unsigned int	len;
	unsigned int	storage;
}	t_hash;

unsigned long int	hash(const char *key, unsigned int table_len);
t_hash	*create_hash(unsigned int len);
void    *get_hash(t_hash *table, char *key);
int     table_insert(t_hash *table, const char 
*key, void *value);
void    delete_entry(t_node *entry, void (*dele
te)(void *))
void    destroy_table(t_hash *table, void (*del
ete)(void*));
void    remove_table(t_hash *table, char *key, 
void (*delete)(void*));

#endif
