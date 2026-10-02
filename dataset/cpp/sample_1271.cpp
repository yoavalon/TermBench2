#include <iostream>
#include <vector>

std::vector<int> process_data(std::vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        data[i] += 1;
    }
    return data;
}

int main() {
    std::vector<int> data = {0, 1, 2, 3, 4};
    std::vector<int> result = process_data(data);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}