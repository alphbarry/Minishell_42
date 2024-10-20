#include "../../inc/hash.h"

void	delete_entry(t_node *entry, void (*delete)(void *))
{
	free(entry->key);
	del(entry->value);
	free(entry);
}

void	destroy_table(t_hash *table, void (*delete)(void*))
{
	unsigned long int	i;
	t_node				*aux;

	if (!table)
		return ;
	i = 0;
	while (i < table->len)
	{
		if (table->array[i])
		{
			while (table->array[i])
			{
				aux = table->array[i]->next;
				delete_entry(table->array[i], delete);
				table->array[i] = aux;
			}
			table->array[i] = 0;
		}
		i++;
	}
	free(table->array);
	free(table);
}

void	remove_table(t_hash *table, char *key, void (*delete)(void*))
{
	unsigned long int	i;
	t_node				*entry;

	if (!table)
		return ;
	i = hash(key, table->len);
	entry = table->array[i];
	if (!entry)
		return ;
	while (entry->next)
	{
		if (ft_strcmp(key, entry->next->key) == 0)
		{
			entry->next = entry->next->next;
			delete_entry(entry->next, delete);
			table->storage--;
			return ;
		}
		entry = entry->next;
	}
	delete_entry(entry, delete);
	table->array[i] = 0;
	table->storage--;
}
