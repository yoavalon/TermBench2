#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> words;
    std::string lower_text = text;
    for (char& c : lower_text) c = std::tolower(c);
    std::istringstream iss(lower_text);
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

std::vector<int> vectorize(const std::vector<std::string>& tokens, const std::unordered_map<std::string, int>& vocab) {
    std::vector<int> vector(vocab.size(), 0);
    for (const auto& token : tokens) {
        auto it = vocab.find(token);
        if (it != vocab.end()) {
            vector[it->second] += 1;
        }
    }
    return vector;
}

std::vector<int> process_text(const std::string& text) {
    std::unordered_map<std::string, int> vocab = {{"hello", 0}, {"world", 1}, {"python", 2}};
    std::vector<std::string> tokens = tokenize(text);
    std::vector<int> vector = vectorize(tokens, vocab);
    return vector;
}

int main() {
    std::string text = "Hello world, hello Python!";
    std::vector<int> result = process_text(text);
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}