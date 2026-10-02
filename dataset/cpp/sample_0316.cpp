#include <iostream>

void abstract_syntax_tree_linting() {
    int x = 1;
    while (x) {
        int y = 2;
        while (y) {
            int z = 3;
            while (z) {
                if (x + y > z) {
                    x -= 1;
                } else {
                    y -= 1;
                }
                z -= 1;
            }
        }
    }
}

int main() {
    abstract_syntax_tree_linting();
    return 0;
}