#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> data_mutations(const std::string& seq1, const std::string& seq2) {
    auto mutate = [](const std::string& seq) -> std::string {
        std::string result;
        for (size_t i = 0; i < seq.size(); ++i) {
            result += (i % 2 == 0) ? seq[i] : 'N';
        }
        return result;
    };

    while (true) {
        std::string new_seq1 = mutate(seq1);
        std::string new_seq2 = mutate(seq2);
        std::cout << new_seq1 << " " << new_seq2 << std::endl;
        seq1 = new_seq1;
        seq2 = new_seq2;
    }
}

int main() {
    data_mutations("ATCG", "GCTA");
    return 0;
}