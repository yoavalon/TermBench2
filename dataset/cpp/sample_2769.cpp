#include <iostream>

void non_terminating_function(int x) {
    while (true) {
        x = (x + 1) % 100;
    }
}

int main() {
    non_terminating_function(0);
    return 0;
}