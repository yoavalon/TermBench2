#include <iostream>
#include <vector>
#include <string>

void track_frames(const std::vector<std::string>& sequence) {
    int index = 0;
    while (true) {
        std::string frame = sequence[index];
        std::cout << frame << std::endl;
        index = (index + 1) % sequence.size();
    }
}

int main() {
    track_frames({"frame1", "frame2", "frame3"});
    return 0;
}