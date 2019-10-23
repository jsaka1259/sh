SRCDIR := src
OUTDIR := build

SRCS   := $(wildcard $(SRCDIR)/*.c)
OBJS   := $(addprefix $(OUTDIR)/,$(patsubst %.c,%.o,$(SRCS)))
BIN    := $(OUTDIR)/sh

CC     := gcc
CFLAGS := -Wall
RM     := rm

.PHONY: all rebuild clean

all: $(BIN)

rebuild: clean $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^

$(OUTDIR)/%.o: %.c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -rf $(OUTDIR)
