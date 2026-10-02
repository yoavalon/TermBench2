#include <iostream>
#include <vector>

int transform(int a, int b) {
    return a + b;
}

int track_sequence(const std::vector<int>& data) {
    int state = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        state = transform(state, data[i]);
    }
    return state;
}

int main() {
    int result = track_sequence({1, 2, 3, 4, 5});
    std::cout << result << std::endl;
    return 0;
}