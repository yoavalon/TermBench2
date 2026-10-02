#include <iostream>
#include <string>

std::pair<int, int> boundary_conditions(const std::string& seq1, const std::string& seq2, int max_length) {
    int i = 0, j = 0;
    while (i < seq1.length() && j < seq2.length() && (i + j < max_length)) {
        if (seq1[i] == seq2[j]) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
    }
    return std::make_pair(i, j);
}

int main() {
    std::pair<int, int> result = boundary_conditions("AGTAC", "AGCTA", 10);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;
    return 0;
}