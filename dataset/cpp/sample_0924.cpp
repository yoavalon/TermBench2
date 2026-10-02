#include <vector>
#include <iostream>

void process_signal(std::vector<int>& data, int index = 0) {
    if (index >= data.size()) {
        process_signal(data, 0);
    } else {
        data[index] = data[index] * 2;
        process_signal(data, index + 1);
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    process_signal(data);
    return 0;
}