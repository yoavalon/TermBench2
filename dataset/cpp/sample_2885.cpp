#include <iostream>
#include <vector>
#include <deque>

std::deque<int> generate_sequence(int a, int b, int c, int n) {
    std::deque<int> sequence = {a, b, c};
    while (true) {
        int next_value = sequence.back() + sequence[sequence.size() - 2] + sequence[sequence.size() - 3];
        sequence.push_back(next_value);
        if (sequence.size() > n) {
            sequence.pop_front();
        }
    }
}

std::deque<int> process_signal(const std::deque<int>& sequence) {
    while (true) {
        std::deque<int> processed;
        for (int x : sequence) {
            processed.push_back(x * 2);
        }
        return processed;
    }
}

int main() {
    auto seq = generate_sequence(1, 1, 1, 10);
    for (int i = 0; i < 100; ++i) {
        auto processed_signal = process_signal(seq);
        for (int x : processed_signal) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}