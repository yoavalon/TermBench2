#include <vector>

std::vector<int> track_sequence(int n, std::vector<int> seq) {
    seq.push_back(n);
    return track_sequence(n + 1, seq);
}

int main() {
    track_sequence(1, {});
    return 0;
}