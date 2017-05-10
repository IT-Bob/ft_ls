#include "ft_ls.h"
#include "libft.h"

t_elem	*add_direc(t_elem *direc, char *name, t_ls *ls, struct stat s)
{
	if (ls->flags[4])
		direc = ls_lstaddtime(&direc, ls_lstnew(name, name, s));
	else
		direc = ls_lstaddalpha(&direc, ls_lstnew(name, name, s));
	ls->nb_direc = 1;
	return (direc);
}
