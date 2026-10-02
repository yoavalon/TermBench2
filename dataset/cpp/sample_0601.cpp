cpp
#include <iostream>

int consensus(int a, int b, int depth = 0) {
    if (a == b || depth > 10) {
        return a;
    }
    int mid = (a + b) / 2;
    return mid > a ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}

int main() {
    std::cout << consensus(1, 10) << std::endl;
    return 0;
}