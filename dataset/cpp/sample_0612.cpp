#include <iostream>
#include <vector>

std::vector<int> track_sequence(int n, std::vector<int> seq = {}) {
    if (n == 0) {
        return seq;
    }
    seq.push_back(n);
    return track_sequence(n - 1, seq);
}

int main() {
    std::vector<int> result = track_sequence(5);
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}