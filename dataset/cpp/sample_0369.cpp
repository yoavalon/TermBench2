#include <iostream>

void plan_flight() {
    int a = 30000;
    int b = 1000;
    while (true) {
        int c = a - b;
        if (c > 10000) {
            a = c;
        } else {
            a += 500;
        }
    }
}

int main() {
    plan_flight();
    return 0;
}