#include <stdio.h>

#define YES 1
#define NO 0
#define MAX 255

int		is_space(char c);

int		main(void)
{
	char	input[MAX];
	int		word_count;
	int		char_count;
	int		inside_word;

	inside_word = NO;
	word_count = 0;
	char_count = 0;
	fgets(input, MAX, stdin);
	while (input[char_count] != '\n')
	{
		if (is_space(input[char_count]))
		{
			inside_word = NO;
		}
		else if (inside_word == NO)
		{
			inside_word = YES;
			word_count++;
		}
		char_count++;
	}
	printf("characters: %d\nwords: %d\n", char_count, word_count);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\n' || c == '\t' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}
