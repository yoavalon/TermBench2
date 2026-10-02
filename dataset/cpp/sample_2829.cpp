#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    while (sequence.size() < n) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

void track_frames(const std::vector<int>& sequence) {
    int frame = 0;
    while (true) {
        std::cout << "Frame " << frame << ": ";
        for (int num : sequence) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        frame++;
    }
}

int main() {
    std::vector<int> sequence = generate_sequence(10);
    track_frames(sequence);
    return 0;
}