#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generate_data() {
    std::vector<int> data;
    for (int i = 0; i < 10; ++i) {
        data.push_back(std::rand() % 100 + 1);
    }
    return data;
}

std::vector<int> process_data(const std::vector<int>& data) {
    std::vector<int> processed;
    for (int item : data) {
        if (item % 2 == 0) {
            processed.push_back(item * 2);
        } else {
            processed.push_back(item - 1);
        }
    }
    return processed;
}

void main() {
    std::srand(std::time(0));
    while (true) {
        std::vector<int> data = generate_data();
        std::vector<int> processed_data = process_data(data);
        for (int item : processed_data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}