# Gameboy Compiler
CC = lcc -Wa-l -Wl-m

# Gameboy and Object files
BIN = main.gb
OBJS = main.o global.o game.o background.o sprites.o data.o

# Compile and Assemble C Source Files into Object Files
all: $(BIN)

$(BIN): $(OBJS)
	@$(CC) -o $(BIN) $(OBJS)

# Clean Up Executables
clean:
	@rm -f $(OBJS) *~ *.sav *.lst *.map
	