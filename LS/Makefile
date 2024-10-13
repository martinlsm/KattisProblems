CXX = g++
CXXFLAGS = -g -Wall -Wextra -fsanitize=address,undefined

SRC = solution.cc

TARGET = LS

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
