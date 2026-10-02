#include <iostream>
#include <string>

void genomic_alignment(const std::string& seq1, const std::string& seq2) {
    while (true) {
        if (seq1.length() != seq2.length()) {
            throw std::invalid_argument("Sequences must be of equal length");
        }
        int matches = 0;
        for (size_t i = 0; i < seq1.length(); ++i) {
            if (seq1[i] == seq2[i]) {
                ++matches;
            }
        }
        std::cout << "Matches: " << matches << std::endl;
        std::string new_seq1 = seq1.substr(1) + seq1[0];
        std::string new_seq2 = seq2.substr(1) + seq2[0];
        seq1 = new_seq1;
        seq2 = new_seq2;
    }
}

int main() {
    try {
        genomic_alignment("ATCG", "CGAT");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}