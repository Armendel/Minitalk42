#include "minitalk.h"

extern int	recieved;

int	send_bit(int pid, int bit)
{
	int	sig;

	sig = SIGUSR1;
	if (bit)
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
	{
		perror("kill error");
		return (0);
	}
	return (1);
}

int	send_char(int pid, char c)
{
	int			i;
	int			wait_count;

	i = 7;
	wait_count = 30;
	while (i >= 0)
	{
		send_bit(pid, (c >> i) % 2);
		while (wait_count >= 0 && !recieved)
		{
			usleep(10);
			wait_count--;
		}
		if (wait_count < 0)
			exit(0);
		recieved = 0;
		i--;
	}
}

int	send_message(char *msg, int pid)
{
	int		i;
	size_t	size;

	size = ft_strlen(msg);
	if (size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		send_char(pid, *(msg + i));
		i++;
	}
	send_char(pid, *(msg + i));
}