#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void parse_documents() {
    while (true) {
        std::string doc = "Sample document text for parsing and tokenization.";
        std::vector<std::string> tokens;
        std::istringstream iss(doc);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        for (const auto& t : tokens) {
            std::cout << t << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    parse_documents();
    return 0;
}