#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    size_t n, s;
    int m;
    std::cin >> n >> s >> m;
    
    std::vector<int> squares;
    squares.reserve(n);
    for (size_t i = 0; i < n; i++) {
        int sq;
        std::cin >> sq;
        squares.push_back(sq);
    }

    size_t frog = s - 1;
    std::unordered_set<size_t> visited;
    int out_of_bounds = 0; // -1 for left, 1 for right, 0 for within.
    bool cycle = false;
    int num_jumps = 0;

    while (true) {
        visited.insert(frog);
        int num = squares[frog];
        int next_sq = static_cast<int>(frog) + num;


        if (num == m) {
            break;
        } else if (next_sq < 0) {
            out_of_bounds = -1;
            break;
        } else if (next_sq >= static_cast<int>(squares.size())) {
            out_of_bounds = 1;
            break;
        } else if (visited.count(next_sq) > 0) {
            cycle = true;
            break;
        }

        frog = next_sq;
        num_jumps += 1;
    }

    if (out_of_bounds == -1) {
        std::cout << "left" << std::endl;
        num_jumps += 1;
    } else if (out_of_bounds == 1) {
        std::cout << "right" << std::endl;
        num_jumps += 1;
    } else if (cycle) {
        std::cout << "cycle" << std::endl;
        num_jumps += 1;
    } else {
        std::cout << "magic" << std::endl;
    }

    std::cout << num_jumps << std::endl;
}
