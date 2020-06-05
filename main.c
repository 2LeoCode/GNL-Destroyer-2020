#include <test.h>
#include "get_next_line.h"

int		main(void)
{
	test_basic();
	test_basic_empty_lines();
	test_basic_end_line();
	test_blank();
	test_long();
	test_new_line();
	test_one_char_lines();
	test_only_new_lines();
	test_random();
	test_single_line();
	test_spongebob();
	test_very_long();
	return (0);
}
