#include <iostream>
#include <vector>

std::vector<int> process_signal(std::vector<int> data, int n) {
    for (int i = 0; i < n; i++) {
        data[i] = 0;
        for (int j = 0; j <= i; j++) {
            data[i] += data[j];
        }
    }
    return data;
}

int main() {
    std::vector<int> result = process_signal({1, 2, 3, 4, 5}, 5);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}