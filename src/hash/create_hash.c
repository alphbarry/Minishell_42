#include "../../inc/hash.h"

t_hash	*create_hash(unsigned int len)
{
	t_hash	*table;

	if (len < 1)
		return NULL;
	table = mallo(sizeof(*table));
	if (!table)
		return NULL;
	table->array = ft_calloc(len, sizeof(t_node));
	if (!table->array)
		return NULL;
	table->len = len;
	table->storage = 0;
	return (table);
}

void	*get_hash(t_hash *table, char *key)
{
	unsigned long int	i;
	t_node				*entry;

	if (!table)
		return NULL;
	i = hash(key, table->len);
	entry = table->array[i];
	while (entry)
	{
		if (ft_strcmp(key, entry->key) == 0)
			break ;
		entry = entry->next;
	}
	if (!entry)
		return NULL;
	return (entry->value);
}

static void	insert_entry(t_hash *table, t_node *new_entry)
{
	unsigned long int	i;
	t_node				*tmp;

	i = hash(new_entry->key, table->len);
	if (!table->array[i])
		table->array[i] = new_entry;
	else
	{
		tmp = table->array[i];
		while (tmp->next)
		{
			if (ft_strcmp(tmp->key, new_entry->key) == 0)
			{
				free(tmp->value);
				tmp->value = new_entry->value;
				free(new_entry->key);
				free(new_entry);
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = new_entry;
	}
}

int	table_insert(t_hash *table, const char *key, void *value)
{
	t_node	*new_entry;

	if (!table)
		return (-1);
	new_entry = ft_calloc(1, sizeof(t_node));
	if (!new_entry)
		return (-1);
	new_entry->key = ft_strdup(key);
	new_entry->value = value;
	new_entry->next = NULL;
	insert_entry(table, new_entry);
	table->storage++;
	return (0);
}
