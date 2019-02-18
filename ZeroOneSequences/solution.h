#include <string>
#include <stack>

using std::string;
using std::stack;

unsigned int swap_determined_nbrs(string& seq) {
    return 0;
}

stack<unsigned int> question_mark_indices(const string& seq) {
    return stack<unsigned int>{};
}

unsigned int set_and_swap_current(const char set_to,
                                  stack<unsigned int> qmarks,
                                  string& seq) {
    // Restore sequence before returning
    // Restore stack before returning
    return 0;
}

unsigned int nbr_of_swaps(string seq) {     // Ändra till referens (&) ??
    unsigned int sum_swaps{0};
    sum_swaps += swap_determined_nbrs(seq);
    stack<unsigned int> qmarks = question_mark_indices(seq);
    sum_swaps += set_and_swap_current('0', qmarks, seq);
    sum_swaps += set_and_swap_current('1', qmarks, seq);
    return sum_swaps % 1000000007;
}
