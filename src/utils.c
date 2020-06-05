#include <test.h>

size_t	get_file_len(char *path)
{
	int fd = open(path, O_RDONLY);
	size_t len = 0;
	int ret = 1;
	char buf[9999];

	while (ret > 0)
	{
		if ((ret = read(fd, buf, 9999)) < 0)
			return (0);
		len += ret;
	}
	close(fd);
	return (len);
}

char	*filetoa(char *path)
{
	char *tmp;
	int fd = open(path, O_RDONLY);
	size_t len = get_file_len(path);

	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1)))
	|| (read(fd, tmp, len) < 0))
		return (NULL);
	close(fd);
	tmp[len] = 0;
	return (tmp);
}

int		ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return ((s1 || s2) ? 1 : 0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_fputstr(int fd, char *s)
{
	int i = -1;

	if (!s)
		return (ft_fputstr(fd, "(null)"));
	while ((fd > 0) && s && s[++i])
		write(fd, &s[i], 1);
	return (i);
}

int		ft_fputs(int fd, char *s)
{
	int i = -1;

	if (!s)
		return (ft_fputs(fd, "(null)"));
	while ((fd > 0) && s && s[++i])
		write(fd, &s[i], 1);
	return (i + write(fd, "\n", 1));
}

int		ft_putstr(char *s)
{
	int i = -1;

	if (!s)
		return (ft_putstr("(null)"));
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}
