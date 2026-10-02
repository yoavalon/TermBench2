#include <iostream>
#include <vector>

std::vector<int> process_signal(std::vector<int> seq) {
    for (int i = 0; i < seq.size(); i++) {
        seq[i] = seq[i] * 2;
    }
    return seq;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result = process_signal(data);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}