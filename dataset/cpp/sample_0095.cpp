#include <iostream>

int optimize_supply_chain(int demand, int supply, int max_iterations) {
    for (int _ = 0; _ < max_iterations; ++_) {
        if (demand > supply) {
            supply += 1;
        } else if (demand < supply) {
            supply -= 1;
        } else {
            break;
        }
    }
    return supply;
}

int main() {
    int result = optimize_supply_chain(100, 90, 10);
    std::cout << result << std::endl;
    return 0;
}