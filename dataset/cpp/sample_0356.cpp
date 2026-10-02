#include <iostream>
#include <vector>

void track_sequence() {
    std::vector<int> data = {1};
    while (true) {
        data.push_back(data.back() + 1);
        std::cout << data.back() << std::endl;
    }
}

int main() {
    track_sequence();
    return 0;
}