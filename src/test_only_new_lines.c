#include <get_next_line.h>
#include <test.h>

void	test_only_new_lines(void)
{
	int fd = open("testfiles/only_new_lines", O_RDONLY);
	int output = open("output/only_new_lines.user", O_WRONLY | O_TRUNC);
	char *line;
	char *test;
	char *real;
	int i = 0;

	while (i++ < 25)
	{
		if (!get_next_line(fd, &line))
			ft_fputstr(output, "[0]");
		ft_fputs(output, line);
		free(line);
	}
	close(output);
	real = filetoa("output/only_new_lines.output");
	test = filetoa("output/only_new_lines.user");
	if (!ft_strcmp(real, test))
	{
		ft_putstr(GRN);
		ft_putstr(" [OK]");
	}
	else
	{
		ft_putstr(RED);
		ft_putstr(" [KO]");
	}
	free(real);
	free(test);
}
