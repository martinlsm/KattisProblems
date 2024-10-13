#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <sstream>
#include <map>

namespace {

bool is_match(const std::string& pattern, const std::string& file) {
    std::vector<std::vector<bool>> dp(file.size() + 1, std::vector<bool>(pattern.size() + 1, false));

    dp[0][0] = true;
    for (size_t j = 0; j < dp[0].size(); j++) {
        if (pattern[j] == '*') {
            dp[0][j + 1] = true;
        } else {
            break;
        }
    }

    for (size_t i = 0; i < file.size(); i++) {
        for (size_t j = 0; j < pattern.size(); j++) {
            if (file[i] == pattern[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else if (pattern[j] == '*') {
                dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
            }
        }
    }

    return dp[file.size()][pattern.size()];
}

}

int main() {
    std::string pattern;
    std::getline(std::cin, pattern);

    std::string n_str;
    std::getline(std::cin, n_str);
    int n = std::stoi(n_str);

    std::vector<std::string> files;
    for (int i = 0; i < n; i++) {
        std::string file;
        std::getline(std::cin, file);
        files.push_back(std::move(file));
    }

    for (const std::string& file : files) {
        if (is_match(pattern, file)) {
            std::cout << file << std::endl;
        }
    }
}
