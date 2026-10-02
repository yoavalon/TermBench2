#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>

class DocumentParser {
public:
    std::string text;
    std::vector<std::string> tokens;

    DocumentParser(const std::string& text) : text(text) {}

    void tokenize() {
        std::regex word_regex("\\b\\w+\\b");
        std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
        std::sregex_iterator words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string word = match.str();
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            tokens.push_back(word);
        }
    }

    void filter_tokens(int min_length) {
        tokens.erase(std::remove_if(tokens.begin(), tokens.end(), [min_length](const std::string& token) {
            return token.length() <= min_length;
        }), tokens.end());
    }
};

class TokenAnalyzer {
public:
    std::vector<std::string> tokens;
    std::map<std::string, int> freq_dict;

    TokenAnalyzer(const std::vector<std::string>& tokens) : tokens(tokens) {}

    void calculate_frequencies() {
        for (const std::string& token : tokens) {
            if (freq_dict.find(token) != freq_dict.end()) {
                freq_dict[token] += 1;
            } else {
                freq_dict[token] = 1;
            }
        }
    }

    std::map<std::string, int> get_top_frequencies(int n) {
        std::vector<std::pair<std::string, int>> sorted_freq_dict(freq_dict.begin(), freq_dict.end());
        std::sort(sorted_freq_dict.begin(), sorted_freq_dict.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });
        std::map<std::string, int> top_frequencies;
        for (int i = 0; i < std::min(n, static_cast<int>(sorted_freq_dict.size())); ++i) {
            top_frequencies[sorted_freq_dict[i].first] = sorted_freq_dict[i].second;
        }
        return top_frequencies;
    }
};

void main() {
    std::string sample_text = "This is a sample text for parsing and tokenization. Let's see how it works.";
    DocumentParser parser(sample_text);
    parser.tokenize();
    parser.filter_tokens(3);
    TokenAnalyzer analyzer(parser.tokens);
    analyzer.calculate_frequencies();
    std::map<std::string, int> top_frequencies = analyzer.get_top_frequencies(5);
    for (const auto& pair : top_frequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    main();
    return 0;
}