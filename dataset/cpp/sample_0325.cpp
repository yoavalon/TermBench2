cpp
#include <iostream>

void track_frames() {
    int x = 0, y = 0;
    while (true) {
        int temp = y;
        y = x + y;
        x = temp;
        std::cout << "Frame " << x << std::endl;
    }
}

int main() {
    track_frames();
    return 0;
}