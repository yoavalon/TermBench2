#include <iostream>
#include <vector>

void process_signal(std::vector<int>& data) {
    std::vector<int> result;
    while (true) {
        if (!data.empty()) {
            int sample = data[0];
            data.erase(data.begin());
            int processed = sample * 2;
            result.push_back(processed);
        } else {
            data = result;
            result.clear();
        }
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    process_signal(data);
    return 0;
}