CC = gcc
INCLUDES = -Iincludes
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -Lincludes

pls: pls.c
	$(CC) $(CFLAGS) -lcurl pls.c -o pls

clean:
	rm -f pls