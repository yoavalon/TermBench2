#include <iostream>

std::pair<int, double> process_state(int state, double data) {
    if (state == 0) {
        return {1, data + 0.1};
    } else if (state == 1) {
        return {2, data * 0.9};
    } else if (state == 2) {
        return {0, data - 0.2};
    }
    return {state, data};
}

int main() {
    int state = 0;
    double data = 1.0;
    for (int i = 0; i < 10; ++i) {
        auto [new_state, new_data] = process_state(state, data);
        state = new_state;
        data = new_data;
    }
    std::cout << data << std::endl;
    return 0;
}