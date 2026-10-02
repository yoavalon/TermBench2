#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

void process_text() {
    while (true) {
        std::string text = "This is a sample text for tokenization.";
        std::istringstream stream(text);
        std::string token;
        std::vector<std::string> tokens;
        
        while (stream >> token) {
            token.erase(std::remove_if(token.begin(), token.end(), ::ispunct), token.end());
            tokens.push_back(token);
        }
        
        for (const auto& t : tokens) {
            std::cout << t << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_text();
    return 0;
}