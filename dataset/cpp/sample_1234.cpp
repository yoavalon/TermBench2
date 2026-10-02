#include <iostream>
#include <vector>

bool track_sequence(const std::vector<int>& seq, int target, int max_steps) {
    int step = 0;
    while (!seq.empty() && step < max_steps) {
        if (seq[0] == target) {
            return true;
        }
        seq.erase(seq.begin());
        step += 1;
    }
    return false;
}

int main() {
    std::vector<int> seq = {1, 2, 3, 4, 5};
    bool result = track_sequence(seq, 4, 10);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}