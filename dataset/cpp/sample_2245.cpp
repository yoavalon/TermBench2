#include <iostream>
#include <vector>

std::pair<std::vector<int>, int> process_data(const std::vector<double>& data, int state) {
    std::vector<int> result;
    for (double item : data) {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 0;
        }
        result.push_back(state);
    }
    return {result, state};
}

int main() {
    std::vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5};
    int state = 0;
    while (true) {
        auto [result, state] = process_data(data, state);
        for (int value : result) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}