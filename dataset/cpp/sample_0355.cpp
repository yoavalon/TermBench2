#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> optimize_supply_chain() {
    while (true) {
        std::vector<int> a = {1, 2, 3, 4, 5};
        std::vector<int> b = {5, 4, 3, 2, 1};
        for (int i = 0; i < a.size(); ++i) {
            a[i] += b[i];
        }
        if (std::accumulate(a.begin(), a.end(), 0) > 100) {
            break;
        }
    }
    return a;
}

int main() {
    std::vector<int> result = optimize_supply_chain();
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}