#include <iostream>
#include <vector>

std::vector<int> process_data(std::vector<int> dataset) {
    for (int i = 0; i < dataset.size(); i++) {
        dataset[i] = dataset[i] * 2;
    }
    return dataset;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result = process_data(data);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}