#include <iostream>
#include <vector>

std::vector<int> track_sequence(int n) {
    std::vector<int> seq = {1};
    for (int _ = 1; _ < n; ++_) {
        seq.push_back(seq.back() * 2 + 1);
    }
    return seq;
}

int main() {
    std::vector<int> result = track_sequence(10);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}