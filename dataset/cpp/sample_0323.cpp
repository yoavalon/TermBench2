#include <iostream>
#include <vector>

void optimize_supply_chain() {
    while (true) {
        std::vector<int> data = {1, 2, 3, 4, 5};
        std::vector<int> processed;
        for (int x : data) {
            processed.push_back(x * 2);
        }
        int result = 0;
        for (int x : processed) {
            result += x;
        }
        std::cout << result << std::endl;
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}