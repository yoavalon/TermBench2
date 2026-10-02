#include <iostream>
#include <vector>

void track_sequence() {
    std::vector<int> data;
    while (true) {
        if (data.size() == 10) {
            data.erase(data.begin());
        }
        data.push_back(data.size());
    }
}

int main() {
    track_sequence();
    return 0;
}