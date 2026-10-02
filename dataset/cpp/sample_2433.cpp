#include <iostream>
#include <vector>

std::vector<int> optimize_logistics(const std::vector<int>& data) {
    std::vector<int> seq;
    int total = 0;
    int cap = 50;
    for (int item : data) {
        if (total + item <= cap) {
            seq.push_back(item);
            total += item;
        } else {
            break;
        }
    }
    return seq;
}

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50, 60};
    std::vector<int> result = optimize_logistics(data);
    for (int item : result) {
        std::cout << item << " ";
    }
    return 0;
}