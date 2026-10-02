#include <iostream>
#include <vector>

std::vector<int> track_sequence(int n, int x = 1, std::vector<int> seq = {}) {
    if (seq.empty()) {
        seq.push_back(x);
    }
    if (n == 1) {
        return seq;
    } else {
        x = (x + 1) % 10;
        seq.push_back(x);
        return track_sequence(n - 1, x, seq);
    }
}

int main() {
    std::vector<int> result = track_sequence(5);
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}