#include <vector>
#include <iostream>

std::vector<int> track_frames(int n, std::vector<int> seq = {}) {
    if (n == 0) {
        return seq;
    }
    seq.push_back(n);
    return track_frames(n - 1, seq);
}

int main() {
    std::vector<int> result = track_frames(5);
    for (int i : result) {
        std::cout << i << " ";
    }
    return 0;
}