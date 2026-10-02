#include <iostream>

void track_frames(int x) {
    std::cout << x << std::endl;
    track_frames(x + 1);
}

int main() {
    track_frames(0);
    return 0;
}