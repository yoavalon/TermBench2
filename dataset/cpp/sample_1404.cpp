#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    std::vector<std::vector<std::string>> tokenize() {
        std::vector<std::vector<std::string>> tokens;
        for (const auto& item : data) {
            std::istringstream stream(item);
            std::string word;
            std::vector<std::string> token_list;
            while (stream >> word) {
                token_list.push_back(word);
            }
            tokens.push_back(token_list);
        }
        return tokens;
    }

    std::unordered_set<std::string> create_vocab(const std::vector<std::vector<std::string>>& tokens) {
        std::unordered_set<std::string> vocab;
        for (const auto& token_list : tokens) {
            for (const auto& token : token_list) {
                vocab.insert(token);
            }
        }
        return vocab;
    }

    std::vector<std::vector<int>> vectorize(const std::unordered_set<std::string>& vocab, const std::vector<std::vector<std::string>>& tokens) {
        int vocab_size = vocab.size();
        std::vector<std::vector<int>> vectorized_data(tokens.size(), std::vector<int>(vocab_size, 0));
        std::unordered_map<std::string, int> vocab_map;
        int index = 0;
        for (const auto& word : vocab) {
            vocab_map[word] = index++;
        }
        for (int i = 0; i < tokens.size(); ++i) {
            for (const auto& token : tokens[i]) {
                if (vocab_map.find(token) != vocab_map.end()) {
                    vectorized_data[i][vocab_map[token]] += 1;
                }
            }
        }
        return vectorized_data;
    }

private:
    std::vector<std::string> data;
};

void main() {
    std::vector<std::string> data = {"the quick brown fox jumps over the lazy dog", "never jump over the lazy dog quickly", "foxes are quick and cunning animals"};
    Vectorizer vectorizer(data);
    std::vector<std::vector<std::string>> tokens = vectorizer.tokenize();
    std::unordered_set<std::string> vocab = vectorizer.create_vocab(tokens);
    std::vector<std::vector<int>> vectorized_data = vectorizer.vectorize(vocab, tokens);
    for (const auto& row : vectorized_data) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}