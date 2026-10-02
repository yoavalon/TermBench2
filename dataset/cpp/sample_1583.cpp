#include <vector>

void track_sequence() {
    std::vector<int> seq = {0};
    while (true) {
        seq.push_back(seq.back() + 1);
    }
}

int main() {
    track_sequence();
    return 0;
}