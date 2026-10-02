#include <iostream>

void simulate_flight() {
    int x = 0, y = 0;
    int dx = 5, dy = 2;
    while (true) {
        x += dx;
        y += dy;
        if (y > 100) {
            dy = -dy;
        }
        if (x > 500) {
            dx = -dx;
        }
        std::cout << "Position: (" << x << ", " << y << ")" << std::endl;
    }
}

int main() {
    simulate_flight();
    return 0;
}