#include "ft_ls.h"
#include "libft.h"

static void	lstiter_reverse(t_elem *lst, t_ls *ls, void (*f)(char *, t_ls *))
{
	if (lst)
	{
		lstiter_reverse(lst->next, ls, f);
		if (lst->next)
			ft_putchar('\n');
		f(lst->name, ls);
	}
}

static void	lstiter(t_elem *lst, t_ls *ls, void (*f)(char *, t_ls *))
{
	while (lst)
	{
		f(lst->name, ls);
		lst = lst->next;
		if (lst)
			ft_putchar('\n');
	}
}

void		ls_direc(t_elem **direc, t_ls *ls)
{
	if (*direc)
	{
		if (ls && ls->nb_files)
			ft_putchar('\n');
		if (ls && ls->flags[3])
			lstiter_reverse(*direc, ls, &print_directory);
		else
			lstiter(*direc, ls, &print_directory);
		//ft_lstdel(direc, &del);
	}
}
