#include <iostream>
#include <string>

void align(const std::string& a, const std::string& b, int i = 0, int j = 0) {
    if (i < a.length() && j < b.length()) {
        align(a, b, i + 1, j + 1);
    } else {
        align(a, b, i, j + 1);
        align(a, b, i + 1, j);
        align(a, b, i + 1, j + 1);
    }
}

int main() {
    align("ACGT", "ACCGT");
    return 0;
}