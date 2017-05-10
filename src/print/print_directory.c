#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/stat.h>
#include <dirent.h>

void	print_directory(char *path, t_ls *ls)
{
	DIR				*direc;
	struct dirent	*content;
	struct stat		stat;
	t_elem			*elem;

	char *str = ft_strjoin(path, "/");
	if ((direc = opendir(path)))
	{
		if (ls->nb_direc > 1)
			ft_printf("%s:\n", path);
		elem = NULL;
		while((content = readdir(direc)))
		{
			stat.st_ino = 0;
			lstat(ft_strjoin(str, content->d_name), &stat);
			if (content->d_name[0] != '.' || ls->flags[1])
				elem = add_files(elem, content->d_name, ls, stat);
		}
		ls_files(&elem, ls);
		closedir(direc);
	}
}
