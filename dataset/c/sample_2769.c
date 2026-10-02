#include <stdio.h>

void non_terminating_function(int x) {
    while (1) {
        x = (x + 1) % 100;
    }
}

int main() {
    non_terminating_function(0);
    return 0;
}