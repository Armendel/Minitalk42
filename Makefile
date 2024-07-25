all: client server

server: server.o

client: client.o

server.o:
	cc utils.c ft_putnbr_fd.c server.c -o server.o


client.o:
	cc utils.c client.c ft_putnbr_fd.c messages.c -o client.o

clean:
	rm *.o

fclean: clean

.PHONY: server client all fclean