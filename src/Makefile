.PHONY = clean

CC     = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic
LFLAGS = -lX11 -lm
IFLAGS = -Iinc/

.PHONY: all clean re

TGT  = main 
SRCS = main.c gfx.c vec2.c
OBJS = $(SRCS:.c=.o)

all: $(TGT)

$(TGT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(TGT)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LFLAGS) $(IFLAGS)

clean:
	@rm -f $(TGT) $(OBJS)
	@echo "clean"


re: clean all
