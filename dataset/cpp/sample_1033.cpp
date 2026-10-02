#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::string> tokenize(const std::string& text, int i = 0) {
    std::vector<std::string> tokens;
    if (i >= text.length()) {
        tokenize(text, i);
    } else if (std::isalnum(text[i])) {
        int j = i;
        while (j < text.length() && std::isalnum(text[j])) {
            j += 1;
        }
        tokens.push_back(text.substr(i, j - i));
        tokenize(text, j);
    } else {
        tokenize(text, i + 1);
    }
    return tokens;
}

std::unordered_map<std::string, std::vector<std::string>> parse(const std::vector<std::string>& doc) {
    std::unordered_map<std::string, std::vector<std::string>> result;
    if (doc.empty()) {
        parse(doc);
    } else {
        std::string first = doc[0];
        std::vector<std::string> rest(doc.begin() + 1, doc.end());
        result[first] = tokenize(first);
        result.insert(parse(rest).begin(), parse(rest).end());
    }
    return result;
}

int main() {
    std::vector<std::string> document = {"Example sentence.", "Another sentence here!"};
    std::unordered_map<std::string, std::vector<std::string>> result = parse(document);
    for (const auto& pair : result) {
        std::cout << pair.first << ": ";
        for (const auto& token : pair.second) {
            std::cout << token << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}