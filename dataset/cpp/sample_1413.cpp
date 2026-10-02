#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>

class TextProcessor {
public:
    TextProcessor(const std::string& text) : text(text) {}

    std::vector<std::string> tokenize() {
        std::regex re("\\b\\w+\\b");
        std::sregex_iterator begin(text.begin(), text.end(), re);
        std::sregex_iterator end;
        std::vector<std::string> tokens;
        for (std::sregex_iterator i = begin; i != end; ++i) {
            tokens.push_back((*i).str());
        }
        return tokens;
    }

    std::vector<std::string> normalize(const std::vector<std::string>& tokens) {
        std::vector<std::string> normalized_tokens;
        for (const auto& token : tokens) {
            std::string lower_token;
            std::transform(token.begin(), token.end(), std::back_inserter(lower_token), ::tolower);
            normalized_tokens.push_back(lower_token);
        }
        return normalized_tokens;
    }

private:
    std::string text;
};

class MutationEngine {
public:
    MutationEngine(const std::vector<std::string>& tokens) : tokens(tokens) {}

    std::vector<std::string> apply_mutation() {
        std::vector<std::string> mutated_tokens;
        for (const auto& token : tokens) {
            std::string mutated_token;
            if (token.length() > 3) {
                mutated_token = token.front() + token.back() + std::string(token.begin() + 1, token.end() - 1);
                std::reverse(mutated_token.begin() + 1, mutated_token.end() - 1);
            } else {
                mutated_token = token;
                std::reverse(mutated_token.begin(), mutated_token.end());
            }
            mutated_tokens.push_back(mutated_token);
        }
        return mutated_tokens;
    }

private:
    std::vector<std::string> tokens;
};

class DatasetGenerator {
public:
    DatasetGenerator(const std::string& text) : text(text), text_processor(text), mutation_engine(nullptr) {}

    std::vector<std::string> generate() {
        auto tokens = text_processor.tokenize();
        auto normalized_tokens = text_processor.normalize(tokens);
        mutation_engine = std::make_unique<MutationEngine>(normalized_tokens);
        auto mutated_tokens = mutation_engine->apply_mutation();
        return mutated_tokens;
    }

private:
    std::string text;
    TextProcessor text_processor;
    std::unique_ptr<MutationEngine> mutation_engine;
};

int main() {
    std::string sample_text = "The quick brown fox jumps over the lazy dog";
    DatasetGenerator dataset_generator(sample_text);
    auto result = dataset_generator.generate();
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}