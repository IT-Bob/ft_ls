#include "libft.h"
#include <stdlib.h>

void	del(void *list, size_t size)
{
	if (size)
		;
	if (list)
		free(list);
	list = NULL;
}
