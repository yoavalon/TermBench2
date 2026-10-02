#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& data) {
    int n = data.size();
    std::vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            result[i] += data[j];
        }
    }
    return result;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> output = process_signal(data);
    for (int i = 0; i < output.size(); ++i) {
        std::cout << output[i] << " ";
    }
    return 0;
}