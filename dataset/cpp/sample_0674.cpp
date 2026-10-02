#include <iostream>

int consensus(int a, int b, int depth = 0) {
    if (a == b) {
        return a;
    }
    if (depth > 10) {
        return -1; // Using -1 to represent None since we can't return None in C++
    }
    int mid = (a + b) / 2;
    return mid < b ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
}

int main() {
    int result = consensus(0, 10);
    std::cout << result << std::endl;
    return 0;
}