#include "ft_ls.h"
#include "libft.h"

void	ls_nonex(t_list **nonex)
{
	if (*nonex)
	{
		print_nonex(*nonex);
		ft_lstdel(nonex, &del);
	}
}
