#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int generate_supply_chain(std::vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] += rand() % 10 + 1;
    }
    return 0;
}

int optimize_inventory(std::vector<int>& data) {
    double threshold = 0.0;
    for (int num : data) {
        threshold += num;
    }
    threshold /= data.size();
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] > threshold) {
            data[i] = static_cast<int>(threshold);
        }
    }
    return 0;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> data;
    for (int i = 0; i < 10; ++i) {
        data.push_back(rand() % 101 + 50);
    }
    generate_supply_chain(data);
    optimize_inventory(data);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}