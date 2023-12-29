/*
# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -Wall -std=c++11

# Target: program
program: main.o utils.o
    $(CXX) $^ -o $@

# Inference rule to build object files from C++ source files
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Target: clean
clean:
    rm -f *.o program

    
*/

