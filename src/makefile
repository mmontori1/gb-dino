# Gameboy Compiler
CC = lcc -Wa-l -Wl-m

# Gameboy and Object files
BIN = main.gb
OBJS = main.o \
		helpers/global.o helpers/mtime.o helpers/clear.o helpers/loop.o \
		models/data.o models/gameState.o \
		controllers/input.o controllers/start.o controllers/game.o controllers/over.o controllers/state.o \
		views/background.o views/window.o views/sprites.o

# Compile and Assemble C Source Files into Object Files
all: $(BIN)

# Compiles Gameboy File and Removes Object Files
gb: $(BIN)
	@make delete

$(BIN): $(OBJS)
	@$(CC) -o $(BIN) $(OBJS)

# Clean Up All Executables
clean:
	@rm -f $(BIN)
	@make delete

# Deletes All Executables Except for Compiled Gameboy File
delete:
	@rm -f $(OBJS) *~ *.sav *.lst *.map
	@find . -name \*.lst -type f -delete
