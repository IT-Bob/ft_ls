#include "ft_ls.h"
#include "libft.h"

void	ls_direc(t_elem **direc)
{
	if (*direc)
	{
		ls_lstiter(*direc, &print_name);
		//ft_lstdel(direc, &del);
	}
}
