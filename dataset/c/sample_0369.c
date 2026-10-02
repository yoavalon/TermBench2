#include <stdio.h>

void plan_flight() {
    int a = 30000;
    int b = 1000;
    while (1) {
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