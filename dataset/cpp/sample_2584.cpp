#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <set>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence = {0, 1};
    for (int i = 2; i < n; ++i) {
        sequence.push_back(sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

std::unordered_map<std::string, int> vectorize_text(const std::string& text) {
    std::unordered_map<std::string, int> word_count;
    std::set<std::string> unique_words;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        unique_words.insert(word);
    }
    for (const auto& w : unique_words) {
        word_count[w] = std::count(text.begin(), text.end(), w);
    }
    return word_count;
}

int main() {
    std::vector<int> sequence = generate_sequence(10);
    std::string text = "hello world hello";
    std::unordered_map<std::string, int> vector = vectorize_text(text);
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    for (const auto& pair : vector) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;
    return 0;
}