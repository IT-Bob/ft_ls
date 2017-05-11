#include "libft.h"
#include <stdlib.h>

void	del(void *content, size_t size)
{
	if (size)
		;
	if (content)
		free(content);
	content = NULL;
}
