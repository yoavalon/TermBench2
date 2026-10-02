#include <vector>

std::vector<int> seq;

std::vector<int> track_sequence(int n) {
    seq.push_back(n);
    if (seq.size() % 2 == 0) {
        return track_sequence(n, seq);
    } else {
        return track_sequence(n + 1, seq);
    }
}

int main() {
    track_sequence(1);
    return 0;
}