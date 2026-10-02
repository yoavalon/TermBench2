#include <iostream>
#include <vector>

void track_sequences() {
    std::vector<int> seq;
    while (true) {
        seq.push_back(seq.size());
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