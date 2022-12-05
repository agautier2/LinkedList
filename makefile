CC ?= gcc
CFLAGS += -Wall --pedantic -Werror 

all:
	$(CC) $(LDFLAGS) -o main $(CFLAGS) linkedList.c main.c -lm -ld

test:
	$(CC) $(LDFLAGS) -g -o test $(CFLAGS) testUnitaire.c linkedList.c -lcunit

clean:
	rm -f *.o test main
