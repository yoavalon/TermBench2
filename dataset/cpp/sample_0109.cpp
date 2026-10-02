#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> tokenize_document(const std::string& doc) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(doc.begin(), doc.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

std::pair<std::string, std::string> analyze_boundaries(const std::vector<std::string>& tokens) {
    std::string start = tokens[0];
    std::string end = tokens.back();
    return {start, end};
}

void main() {
    std::string doc = "This is a sample document for tokenization and boundary analysis.";
    std::vector<std::string> tokens = tokenize_document(doc);
    auto [start, end] = analyze_boundaries(tokens);
    std::cout << "Start: " << start << ", End: " << end << std::endl;
}

int main() {
    main();
    return 0;
}