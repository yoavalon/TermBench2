#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> words;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        for (char& c : word) {
            c = std::tolower(c);
        }
        words.push_back(word);
    }
    return words;
}

std::vector<int> vectorize(const std::vector<std::string>& tokens, const std::map<std::string, int>& vocab) {
    std::vector<int> vector(vocab.size(), 0);
    for (const std::string& token : tokens) {
        if (vocab.find(token) != vocab.end()) {
            vector[vocab.at(token)] += 1;
        }
    }
    return vector;
}

void main() {
    std::string text = "hello world hello";
    std::map<std::string, int> vocab = {{"hello", 0}, {"world", 1}};
    std::vector<std::string> tokens = tokenize(text);
    std::vector<int> vector = vectorize(tokens, vocab);
    for (int v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}