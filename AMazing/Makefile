CXX = g++
CC  = $(CXX)

CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O0 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g -fsanitize=address

# Targets
PROGS = run_test main_stdin testlist

all: $(PROGS)

run_test: run_test.o solution.o testlist
	$(CXX) $(CXXFLAGS) -o run_test solution.o run_test.o

main_stdin: main_stdin.o solution.o

testlist: $(wildcard test/*.in)
	python gen_testlist.py

.PHONY: all clean

clean:
	rm -f *.o test/*.out $(PROGS)
