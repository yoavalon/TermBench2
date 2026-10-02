#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::pair<std::vector<int>, std::vector<int>> data_mutations() {
    std::vector<int> supply = {100, 200, 300, 400, 500};
    std::vector<int> demand = {120, 180, 250, 300, 420};
    for (int i = 0; i < 5; i++) {
        int idx = rand() % 5;
        supply[idx] += rand() % 41 - 20;
        demand[idx] += rand() % 41 - 20;
    }
    return std::make_pair(supply, demand);
}

int main() {
    srand(time(0));
    auto result = data_mutations();
    for (int s : result.first) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    for (int d : result.second) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    return 0;
}