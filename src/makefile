# Gameboy Compiler
CC = lcc

# Compile and Assemble C Source Files into Object Files
gb: main.c *.h
	@$(CC) -o main.gb main.c *.h

# Clean Up Executables
clean:
	@rm -f *.gb *.sav