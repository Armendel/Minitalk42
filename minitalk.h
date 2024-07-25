#ifndef MINITALK_H
# define MINITALK_H

#define WORD_SIZE 4
#include <stddef.h>
#include "utils.h"

int		send_bit(int pid, int bit);
int		send_char(int pid, char c);
int		send_message(char *msg, int pid);

#endif