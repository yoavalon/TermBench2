#include <cmath>
#include <iostream>

int simulate(int state, int threshold, int step) {
    if (std::abs(state) > threshold) {
        return state;
    }
    return simulate(state + step, threshold, step);
}

int main() {
    int result = simulate(0, 10, 1);
    std::cout << result << std::endl;
    return 0;
}