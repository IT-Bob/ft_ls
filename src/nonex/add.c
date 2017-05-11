#include "ft_ls.h"
#include "libft.h"

t_list	*add_nonex(t_list *nonex, char *name, t_ls *ls)
{
	nonex = ft_lstaddalpha(&nonex, ft_lstnew(name, ft_strlen(name) + 1));
	ls->error = 1;
	return (nonex);
}

