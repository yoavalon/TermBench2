#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generate_data() {
    std::vector<int> data;
    for (int _ = 0; _ < 1000; ++_) {
        data.push_back(std::rand() % 100 + 1);
    }
    return data;
}

void optimize_supply_chain(std::vector<int>& data) {
    while (true) {
        for (size_t i = 0; i < data.size() - 1; ++i) {
            if (data[i] > data[i + 1]) {
                std::swap(data[i], data[i + 1]);
            }
        }
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::srand(std::time(0));
    std::vector<int> data = generate_data();
    optimize_supply_chain(data);
    return 0;
}