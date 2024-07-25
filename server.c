#include "utils.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;
	static int				shift = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	else if (client_pid != info->si_pid)
	{
		if (kill(info->si_pid, SIGUSR2) == -1)
		{
			perror("kill error");
			return ;
		}
		return ;
	}
	c |= (sig == SIGUSR2);
	if (++shift == 8)
	{
		shift = 0;
		if (!c)
		{
			client_pid = 0;
			c = 0;
			shift = 0;
			write(2, "\n", 1);
			return ;
		}
		usleep(100);
		write(2, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
	if (kill(client_pid, SIGUSR1) == -1) // confirm the bit reception
	{
		perror("kill error");
		return ;
	}
}

int main(void)
{
	struct	sigaction sa;
	pid_t	pid;

	pid = getpid();
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		perror("sigaction 1 error");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		perror("sigaction 2 error");
		return (1);
	}
	write(2, "PID Server : ", 13);
	ft_putnbr_fd(pid, 2);
	write(2, "\n", 1);
	while (1)
		pause();
	return (0);
}
