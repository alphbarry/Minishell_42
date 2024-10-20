#include "../../inc/hash.h"

unsigned long int	hash(const char *key, unsigned int table_len)
{
	unsigned long int	hash;
	unsigned int		i;

	hash = 5381;
	i = 0;
	while (key && key[i])
		hash = ((hash << 5) + hash) + key[i++];
	return (hash % table_len);
}
