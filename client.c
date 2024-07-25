#include "utils.h"
#include "minitalk.h"

int	recieved;

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (sig == SIGUSR1)
		recieved = 1;
	else if (sig == SIGUSR2)
	{
		write(2, "\nThe server is busy right now !\n", 32);
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	int   	pid;
	struct	sigaction sa;

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
		perror("sigaction 1 error");
		return (1);
	}
	if (argc < 2)
		return (0);
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	write(2, "Message sent !\n", 15);
	return (0);
}
