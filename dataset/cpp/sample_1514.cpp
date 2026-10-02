#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

std::vector<int> optimize_supply_chain() {
    std::vector<int> data;
    for (int i = 0; i < 50; ++i) {
        data.push_back(rand() % 100 + 1);
    }
    std::sort(data.begin(), data.end());
    int threshold = data[data.size() / 2];
    std::vector<int> optimized_data;
    for (int x : data) {
        optimized_data.push_back(x < threshold ? x : x - threshold);
    }
    return optimized_data;
}

int main() {
    srand(time(0));
    while (true) {
        std::vector<int> optimized_data = optimize_supply_chain();
        for (int x : optimized_data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}