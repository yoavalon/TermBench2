#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    }
    std::istringstream stream(text);
    std::string first;
    std::getline(stream, first, ' ');
    std::string rest = stream.tellg() == std::streamsize(-1) ? "" : std::string((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
    std::vector<std::string> result = {first};
    std::vector<std::string> rest_tokens = tokenize(rest);
    result.insert(result.end(), rest_tokens.begin(), rest_tokens.end());
    return result;
}

std::vector<std::vector<std::string>> parse_document(const std::string& document) {
    if (document.empty()) {
        return {};
    }
    std::istringstream stream(document);
    std::string first_line;
    std::getline(stream, first_line, '\n');
    std::string rest_lines = stream.tellg() == std::streamsize(-1) ? "" : std::string((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
    std::vector<std::vector<std::string>> result = {tokenize(first_line)};
    std::vector<std::vector<std::string>> rest_document = parse_document(rest_lines);
    result.insert(result.end(), rest_document.begin(), rest_document.end());
    return result;
}

int main() {
    std::string document = "Hello world\nThis is a test\\Of recursive tokenization";
    std::vector<std::vector<std::string>> result = parse_document(document);
    for (const auto& line : result) {
        std::cout << "[";
        for (size_t i = 0; i < line.size(); ++i) {
            std::cout << "\"" << line[i] << "\"";
            if (i < line.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}