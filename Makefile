CC= gcc
STD= -std=c99
CFLAGS= -c -Wall -Werror -Wextra
OBJS= core.o

LIB = loglib.a

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

%.o: %.c
	$(CC) $(STD) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o $(LIB)

.PHONY: all clean
