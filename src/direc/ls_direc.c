#include "ft_ls.h"
#include "libft.h"

void	ls_direc(t_elem **direc, t_ls *ls)
{
	if (*direc)
	{
		if (ls && ls->nb_files)
			ft_putchar('\n');
		if (ls && ls->flags[3])
			ls_lstiter_reverse(*direc, &print_name);
		else
			ls_lstiter(*direc, &print_name);
		//ft_lstdel(direc, &del);
	}
}
