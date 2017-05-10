#include "ft_ls.h"
#include "libft.h"

void	ls_files(t_elem **files)
{
	if (*files)
	{
		ls_lstiter(*files, &print_name);
		//ft_lstdel(nonex, &del);
	}
}
