#include <iostream>
#include <string>
#include <utility>

std::pair<int, std::string> align(const std::string& seq1, const std::string& seq2) {
    if (seq1.empty() || seq2.empty()) {
        return {0, ""};
    }
    if (seq1[0] == seq2[0]) {
        auto [score, alignment] = align(seq1.substr(1), seq2.substr(1));
        return {score + 1, std::string(1, seq1[0]) + alignment};
    } else {
        auto [score1, alignment1] = align(seq1.substr(1), seq2);
        auto [score2, alignment2] = align(seq1, seq2.substr(1));
        if (score1 > score2) {
            return {score1, "-" + alignment1};
        } else {
            return {score2, alignment2 + "-"};
        }
    }
}

int main() {
    std::string seq1 = "AGCTG";
    std::string seq2 = "AGGCT";
    auto [score, alignment] = align(seq1, seq2);
    std::cout << score << " " << alignment << std::endl;
    return 0;
}