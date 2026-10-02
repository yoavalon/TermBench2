#include <iostream>
#include <string>

void main() {
    std::string a = "AGCTAGCTAGCT";
    std::string b = "AGCTCGCTAGCT";
    int i = 0;
    while (true) {
        if (i < a.length()) {
            if (a[i] != b[i]) {
                a[i] = b[i];
            }
            i += 1;
        } else {
            i = 0;
        }
    }
}