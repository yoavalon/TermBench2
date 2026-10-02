#include <iostream>
#include <vector>

void track_sequences() {
    std::vector<int> seq = {0};
    while (true) {
        seq.push_back(seq.back() + 1);
        if (seq.size() > 10) {
            seq.erase(seq.begin());
        }
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    track_sequences();
    return 0;
}