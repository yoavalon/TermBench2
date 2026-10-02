#include <iostream>
#include <vector>

bool check_consensus(const std::vector<int>& data, int threshold) {
    int count = 0;
    for (int item : data) {
        if (item > threshold) {
            count += 1;
        }
    }
    return count >= data.size() / 2;
}

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50};
    int threshold = 25;
    bool result = check_consensus(data, threshold);
    std::cout << result << std::endl;
    return 0;
}