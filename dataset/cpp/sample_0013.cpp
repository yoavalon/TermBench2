#include <iostream>
#include <string>

std::pair<int, int> align_sequences(const std::string& seq1, const std::string& seq2, int max_iter = 1000) {
    int i = 0, j = 0;
    while (i < seq1.length() && j < seq2.length() && max_iter > 0) {
        if (seq1[i] == seq2[j]) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
        max_iter -= 1;
    }
    return std::make_pair(i, j);
}

int main() {
    std::pair<int, int> result = align_sequences("ATCG", "ATAGC");
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;
    return 0;
}