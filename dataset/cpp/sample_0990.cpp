#include <vector>
#include <iostream>

std::vector<int> track_sequence(int n, std::vector<int> seq = std::vector<int>()) {
    seq.push_back(n);
    return track_sequence(n + 1, seq);
}

int main() {
    track_sequence(0);
    return 0;
}