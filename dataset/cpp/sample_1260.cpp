#include <iostream>
#include <vector>

std::vector<int> process_sequence(std::vector<int> data) {
    if (data.empty()) {
        return data;
    }
    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (data[i] == data[i + 1]) {
            data[i + 1] = 0; // Using 0 to represent None
        }
    }
    std::vector<int> result;
    for (int x : data) {
        if (x != 0) {
            result.push_back(x);
        }
    }
    return result;
}

int main() {
    std::vector<int> main_data = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    std::vector<int> processed_data = process_sequence(main_data);
    for (int x : processed_data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}