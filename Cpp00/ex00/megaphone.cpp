#include <iostream>

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

void	ft_putstrpp(const char *str)
{
	while (*str)
	{
		std::cout << to_upper(*str);
		str++;
	}
	return ;
}

int	main(int c, char **v)
{
	int	i;

	i = 0;
	if (c <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (++i < c)
			ft_putstrpp(v[i]);
	}
	return (1);
}