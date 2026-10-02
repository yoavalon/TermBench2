#include <iostream>
#include <vector>

std::vector<int> track_sequence(std::vector<int> data) {
    auto mutate = [](const std::vector<int>& frame) -> std::vector<int> {
        std::vector<int> result;
        for (int x : frame) {
            result.push_back(x + 1);
        }
        return result;
    };
    for (int i = 0; i < 5; ++i) {
        data = mutate(data);
    }
    return data;
}

int main() {
    std::vector<int> result = track_sequence({0, 1, 2, 3});
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}