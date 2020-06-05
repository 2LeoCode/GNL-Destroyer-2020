#include <get_next_line.h>
#include <test.h>

void	test_basic_end_line(void)
{
	int fd = open("testfiles/basic_end_line", O_RDONLY);
	int output = open("output/basic_end_line.user", O_WRONLY | O_TRUNC);
	char *line;
	char *test;
	char *real;
	int i = 0;

	while (i++ < 13)
	{
		if (!get_next_line(fd, &line))
			ft_fputstr(output, "[0]");
		ft_fputs(output, line);
		free(line);
	}
	close(output);
	real = filetoa("output/basic_end_line.output");
	test = filetoa("output/basic_end_line.user");
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
