#include "ft_ls.h"
#include "libft.h"

t_elem	*add_files(t_elem *files, char *name, t_ls *ls, struct stat s)
{
	if (ls && ls->flags[4])
		files = ls_lstaddtime(&files, ls_lstnew(name, s));
	else
		files = ls_lstaddalpha(&files, ls_lstnew(name, s));
	if(ls)
		ls->nb_files = 1;
	return (files);
}
