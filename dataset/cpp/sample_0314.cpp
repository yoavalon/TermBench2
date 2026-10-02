#include <iostream>

void boundary_conditions() {
    int frame = 0;
    while (true) {
        std::cout << "Frame " << frame << std::endl;
        frame += 1;
    }
}

int main() {
    boundary_conditions();
    return 0;
}