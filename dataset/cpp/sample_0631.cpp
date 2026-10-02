cpp
#include <iostream>
#include <vector>

std::vector<int> track_sequence(int n, std::vector<int> seq) {
    if (n == 0) {
        return seq;
    } else {
        seq.push_back(n);
        return track_sequence(n - 1, seq);
    }
}

int main() {
    track_sequence(5, {});
    return 0;
}