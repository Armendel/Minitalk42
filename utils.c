#include <stddef.h>

static  int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

static  int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		sign = -1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	str += i;
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}
