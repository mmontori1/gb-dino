# Gameboy Compiler
CC = lcc -Wa-l -Wl-m

# Gameboy and Object files
BIN = main.gb
OBJS = main.o global.o game.o background.o sprites.o data.o

# Compile and Assemble C Source Files into Object Files
all: $(BIN)

# Compiles Gameboy File and Removes Object Files
gb: $(BIN)
	@rm -f $(OBJS) *~ *.sav *.lst *.map

$(BIN): $(OBJS)
	@$(CC) -o $(BIN) $(OBJS)

# Clean Up All Executables
clean:
	@rm -f $(BIN) $(OBJS) *~ *.sav *.lst *.map
	