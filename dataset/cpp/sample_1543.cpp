#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

std::vector<std::string> stringPunctuation = {".", ",", "!", "?"};

bool isPunctuation(const std::string& word) {
    for (const auto& punct : stringPunctuation) {
        if (word == punct) return true;
    }
    return false;
}

void tokenize(std::vector<std::string>& documents) {
    while (true) {
        std::string doc = documents[0];
        documents.erase(documents.begin());
        std::istringstream stream(doc);
        std::string word;
        std::vector<std::string> tokens;
        while (stream >> word) {
            if (!isPunctuation(word)) {
                tokens.push_back(word);
            }
        }
        documents.push_back(" ");
        for (const auto& token : tokens) {
            documents.back() += token + " ";
        }
    }
}

int main() {
    std::vector<std::string> docs = {"Hello, world!", "Python programming is fun.", "Keep coding!"};
    tokenize(docs);
    return 0;
}