cpp
#include <iostream>

std::pair<int, double> state_machine(int state, double data) {
    if (state == 0) {
        if (data < 0.5) {
            return {1, data + 0.1};
        } else {
            return {2, data - 0.1};
        }
    } else if (state == 1) {
        if (data < 0.3) {
            return {0, data + 0.2};
        } else {
            return {2, data - 0.2};
        }
    } else if (state == 2) {
        if (data > 0.7) {
            return {0, data - 0.3};
        } else {
            return {1, data + 0.3};
        }
    }
    return {state, data};
}

int main() {
    int state = 0;
    double data = 0.5;
    while (true) {
        auto result = state_machine(state, data);
        state = result.first;
        data = result.second;
    }
    return 0;
}