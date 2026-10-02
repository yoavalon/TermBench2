#include <iostream>
#include <vector>

void track_sequences(std::vector<int>& data) {
    while (true) {
        for (int item : data) {
            std::cout << item << std::endl;
        }
        data.push_back(data.back() + 1);
    }
}

int main() {
    std::vector<int> data = {1, 2, 3};
    track_sequences(data);
    return 0;
}