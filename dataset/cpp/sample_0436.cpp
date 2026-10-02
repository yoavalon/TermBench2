#include <iostream>
#include <vector>

void frame_tracker() {
    std::vector<int> seq;

    auto update_sequence = [&seq](int frame) {
        seq.push_back(frame);
        return seq;
    };

    auto analyze_sequence = [&seq](const std::vector<int>& seq) {
        if (seq.size() > 10) {
            seq.erase(seq.begin());
        }
        return seq;
    };

    while (true) {
        int frame = seq.size() + 1;
        seq = analyze_sequence(update_sequence(frame));
    }
}

int main() {
    frame_tracker();
    return 0;
}