all:client.o server.o
	gcc client.c server.c
client.o: client.c header.h
	gcc -c client.c 
server.o:server.c header.h
	gcc -c server.c