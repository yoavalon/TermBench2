cpp
#include <iostream>
#include <vector>

std::vector<int> update_sequence(const std::vector<int>& sequence, int step) {
    std::vector<int> new_sequence;
    for (int item : sequence) {
        new_sequence.push_back(item + step);
    }
    return new_sequence;
}

bool check_boundary(const std::vector<int>& sequence, int limit) {
    for (int item : sequence) {
        if (item >= limit) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> seq = {0, 1, 2};
    int step = 1;
    int limit = 10;
    while (!check_boundary(seq, limit)) {
        seq = update_sequence(seq, step);
    }
    std::cout << "Boundary reached: ";
    for (int item : seq) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}