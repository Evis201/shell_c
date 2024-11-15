.PHONY: all clean

PROGS=hello ls
CC=gcc
CFLAGS=
LDFLAGS=

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

%.s: %.c
	$(CC) -S $< 

clean:
	rm -f $(PROGS) *.s
