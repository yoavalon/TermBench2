cpp
#include <iostream>
#include <vector>

std::vector<int> process_signal(std::vector<int> data) {
    for (int _ = 0; _ < data.size(); ++_) {
        for (int i = 0; i < data.size(); ++i) {
            data[i] *= 2;
        }
    }
    return data;
}

int main() {
    std::vector<int> signal = {1, 2, 3, 4, 5};
    std::vector<int> result = process_signal(signal);
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}