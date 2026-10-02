#include <iostream>

std::pair<int, double> state_machine(int state, double data) {
    if (state == 0) {
        if (data < 0.5) {
            return std::make_pair(1, data * 2);
        } else {
            return std::make_pair(2, data / 2);
        }
    } else if (state == 1) {
        if (data > 1.5) {
            return std::make_pair(0, data - 1);
        } else {
            return std::make_pair(1, data + 0.1);
        }
    } else if (state == 2) {
        if (data < 0.1) {
            return std::make_pair(0, data * 10);
        } else {
            return std::make_pair(2, data - 0.2);
        }
    }
    return std::make_pair(state, data);
}

int main() {
    int state = 0;
    double data = 0.3;
    while (true) {
        auto result = state_machine(state, data);
        state = result.first;
        data = result.second;
    }
    return 0;
}