#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define GRN "\x1B[32m"
# define RED "\x1B[31m"
# define WHT "\x1B[37m"

size_t	get_file_len(char *path);
char	*filetoa(char* path);
int		ft_strcmp(char *s1, char *s2);
int		ft_fputstr(int fd, char *s);
int		ft_fputs(int fd, char *s);
int		ft_putstr(char *s);
void	test_basic_empty_lines(void);
void	test_basic_end_line(void);
void	test_basic(void);
void	test_blank(void);
void	test_long(void);
void	test_new_line(void);
void	test_one_char_lines(void);
void	test_only_new_lines(void);
void	test_random(void);
void	test_single_line(void);
void	test_single_long_line(void);
void	test_spongebob(void);
void	test_very_long(void);
# endif
