BIN    := sh
OBJS   := main.o io.o getcmd.o utils.o
INC    := ./

CC     := gcc
CFLAGS := -Wall
INC    := -I $(INC)
RM     := rm

.SUFFIXES: .c .o

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -f $(OBJS) $(BIN)

.PHONY: rebuild
rebuild: clean $(BIN)

