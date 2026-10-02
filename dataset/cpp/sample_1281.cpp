#include <iostream>
#include <vector>

std::vector<int> process_sequence(std::vector<int> seq) {
    for (int i = 0; i < seq.size(); i++) {
        seq[i] = seq[i] * 2;
        if (seq[i] > 100) {
            break;
        }
    }
    return seq;
}

int main() {
    std::vector<int> data = {5, 10, 15, 20, 25};
    std::vector<int> result = process_sequence(data);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}