#include <iostream>
#include <vector>

std::vector<int> calculate_altitude_sequence() {
    int a = 3000, b = 4000;
    std::vector<int> sequence = {a, b};
    for (int _ = 0; _ < 8; ++_) {
        a = b;
        b = (a + b) / 2;
        sequence.push_back(b);
    }
    return sequence;
}

int main() {
    std::vector<int> result = calculate_altitude_sequence();
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}