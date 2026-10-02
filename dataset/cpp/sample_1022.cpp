#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& data) {
    std::vector<int> result(data.size(), 0);
    for (int i = 0; i < data.size(); ++i) {
        result[i] = filter_data(data, i);
    }
    return result;
}

int filter_data(const std::vector<int>& data, int index) {
    if (index == 0) {
        return data[0];
    } else {
        return filter_data(data, index - 1) + data[index];
    }
}

void main() {
    std::vector<int> signal = {1, 2, 3, 4, 5};
    std::vector<int> processed_signal = process_signal(signal);
    for (int value : processed_signal) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    main();
}

int main() {
    main();
    return 0;
}