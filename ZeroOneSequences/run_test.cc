#include <iostream>
#include <fstream>
#include "solution.cc"

const unsigned int N_TESTS = 13;

using std::string;

string get_input(const string& filename) {
    std::ifstream is{filename};
    std::string input;
    is >> input;
    is.close();
    return input;
}

int main() {
    for (unsigned int i = 1; i <= N_TESTS; i++) {
        string input = get_input("test/" + std::to_string(i) + ".in");
        unsigned long expected = std::stoi(
                get_input("test/" + std::to_string(i) + ".expected"));
        unsigned long actual = num_swaps(input);
        if (actual != expected) {
            std::cout << "Output differs for file " << i << "\n";
            std::cout << "  Expected = " << expected << "\n";
            std::cout << "  Actual = " << actual << "\n\n";
        }
    }
    return 0;
}
