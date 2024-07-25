#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

int     ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);

#endif