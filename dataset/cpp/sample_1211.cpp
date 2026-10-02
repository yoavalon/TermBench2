#include <iostream>

int calculate_altitude() {
    int a = 30000;
    int b = 200;
    int c = 1000;
    for (int i = 0; i < 5; i++) {
        a += b;
        b -= c;
        if (b <= 0) {
            break;
        }
    }
    return a;
}

int main() {
    calculate_altitude();
    return 0;
}