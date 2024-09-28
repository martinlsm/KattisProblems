# Compiler
CXX = g++
CXXFLAGS = -g -Wall -Wextra -pthread

# Source files
SRC = solution.cc

# Executables
TARGET = armpit_computation

# Default rule
all: $(TARGET)

# Compile the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up the compiled files
clean:
	rm -f $(TARGET)
