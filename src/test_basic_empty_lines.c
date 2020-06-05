#include <get_next_line.h>
#include <test.h>

void	test_basic_empty_lines(void)
{
	int fd = open("testfiles/basic_empty_lines", O_RDONLY);
	int output = open("output/basic_empty_lines.user", O_WRONLY | O_TRUNC);
	char *line;
	char *test;
	char *real;
	int i = 0;

	while (i++ < 29)
	{
		if (!get_next_line(fd, &line))
			ft_fputstr(output, "[0]");
		ft_fputs(output, line);
		free(line);
	}
	close(output);
	real = filetoa("output/basic_empty_lines.output");
	test = filetoa("output/basic_empty_lines.user");
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
	ft_putstr(WHT);
	free(real);
	free(test);
}
