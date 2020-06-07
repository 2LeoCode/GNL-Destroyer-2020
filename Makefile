#Enter your GNL path here
PATH_GNL	= ../get_next_line-v2

NAME		= tester
SRCDIR		= src
OBJDIR		= obj
INCDIR		= inc
SRC			=	test_basic_empty_lines.c\
				test_basic_end_line.c\
				test_basic.c\
				test_blank.c\
				test_long.c\
				test_new_line.c\
				test_one_char_lines.c\
				test_only_new_lines.c\
				test_random.c\
				test_single_line.c\
				test_single_long_line.c\
				test_spongebob.c\
				test_very_long.c\
				utils.c
OBJ			= $(SRC:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -I $(INCDIR)
GREEN		= \x1b[32m
PURPLE		= \x1b[35m

all: $(NAME)
	@(sh compile.sh "$(addprefix ${OBJDIR}/, ${OBJ})")

test: all
	@sh test.sh

$(NAME): gnl $(addprefix ${OBJDIR}/, ${OBJ})
	@(echo '\n$(NAME) is up to date')

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@(printf '$(PURPLE)\rCompiling' && gcc $(CFLAGS) -c $< -o $@ && printf ' ($<)                 ')

gnl:
	cp $(PATH_GNL)/get_next_line.c . && cp $(PATH_GNL)/get_next_line_utils.c . && cp $(PATH_GNL)/get_next_line.h . && cp get_next_line.h $(INCDIR)

$(OBJDIR):
	@(mkdir $(OBJDIR))

clean:
	@(rm -rf $(OBJDIR) && echo '$(GREEN)Removed [obj]')

fclean: clean
	@(rm -f $(NAME) && echo '$(GREEN)Removed [$(NAME)]' && sh clean.sh)

re: fclean all
