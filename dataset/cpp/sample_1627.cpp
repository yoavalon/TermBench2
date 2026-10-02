#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

std::vector<std::string> tokenize_document(const std::string& text) {
    std::string lower_text;
    for (char c : text) {
        lower_text += std::tolower(c);
    }
    std::string clean_text;
    for (char c : lower_text) {
        if (!std::ispunct(c)) {
            clean_text += c;
        }
    }
    std::istringstream iss(clean_text);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

void process_documents(const std::vector<std::string>& documents) {
    while (true) {
        for (const std::string& doc : documents) {
            std::vector<std::string> tokens = tokenize_document(doc);
            for (const std::string& token : tokens) {
                std::cout << token << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> docs = {"Hello, world!", "Python is great.", "Data parsing is fun!"};
    process_documents(docs);
    return 0;
}