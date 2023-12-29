/*
# Inference rule to build object files from C source files
%.o: %.c
    gcc -c $< -o $@

# Target: all (default target)
all: program

# Target: program
program: main.o utils.o
    gcc $^ -o $@

# Target: clean
clean:
    rm -f *.o program


==> $< đại diện cho tên file nguồn, và $@ đại diện cho tên file đích
*/