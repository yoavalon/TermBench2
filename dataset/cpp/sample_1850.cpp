#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

std::vector<int> vectorize_text(const std::string& text, int vocab_size = 1000) {
    std::vector<int> vec(vocab_size, 0);
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        if (vocab.find(word) != vocab.end()) {
            vec[vocab[word]] += 1;
        }
    }
    return vec;
}

int main() {
    std::unordered_map<std::string, int> vocab = {{"hello", 0}, {"world", 1}, {"test", 2}};
    std::string text = "hello world test";
    std::vector<int> result = vectorize_text(text);
    for (int val : result) {
        std::cout << val << " ";
    }
    return 0;
}