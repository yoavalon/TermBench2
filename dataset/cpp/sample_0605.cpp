#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& data, int index = 0) {
    if (index >= data.size()) {
        return {};
    }
    int processed = data[index] * 2;
    std::vector<int> result = {processed};
    std::vector<int> rest = process_signal(data, index + 1);
    result.insert(result.end(), rest.begin(), rest.end());
    return result;
}

int main() {
    std::vector<int> signal = {1, 2, 3, 4, 5};
    std::vector<int> result = process_signal(signal);
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}