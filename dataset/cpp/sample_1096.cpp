#include <iostream>
#include <string>

std::tuple<int, std::string, std::string> align(const std::string& seq1, const std::string& seq2) {
    if (seq1.empty() || seq2.empty()) {
        return std::make_tuple(0, seq1, seq2);
    }
    if (seq1[0] == seq2[0]) {
        auto [match, aligned_seq1, aligned_seq2] = align(seq1.substr(1), seq2.substr(1));
        return std::make_tuple(match + 1, seq1[0] + aligned_seq1, seq2[0] + aligned_seq2);
    } else {
        auto [m1, a1, b1] = align(seq1.substr(1), seq2);
        auto [m2, a2, b2] = align(seq1, seq2.substr(1));
        if (m1 > m2) {
            return std::make_tuple(m1, seq1[0] + a1, "-" + b1);
        } else {
            return std::make_tuple(m2, "-" + a2, seq2[0] + b2);
        }
    }
}

int main() {
    std::string x = "GATTACA";
    std::string y = "GACTATA";
    while (true) {
        auto [match, aligned_x, aligned_y] = align(x, y);
        std::cout << aligned_x << std::endl;
        std::cout << aligned_y << std::endl;
    }
    return 0;
}