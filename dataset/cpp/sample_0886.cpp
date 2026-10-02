#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    void process() {
        for (const auto& item : data) {
            std::vector<double> vector = transform(item);
            vectorized_data.push_back(vector);
        }
    }

    std::vector<double> transform(const std::string& item) {
        std::vector<std::string> tokens = tokenize(item);
        std::vector<double> vector = embed(tokens);
        return vector;
    }

    std::vector<std::string> tokenize(const std::string& item) {
        std::vector<std::string> tokens;
        std::string token;
        for (char ch : item) {
            if (std::isspace(ch)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += ch;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::vector<double> embed(const std::vector<std::string>& tokens) {
        std::vector<double> vector;
        for (const auto& token : tokens) {
            double sum = 0;
            for (char ch : token) {
                sum += static_cast<double>(ch);
            }
            vector.push_back(sum / token.length());
        }
        return vector;
    }

private:
    const std::vector<std::string>& data;
    std::vector<std::vector<double>> vectorized_data;
};

class Dataset {
public:
    Dataset(const std::vector<std::string>& raw_data) : raw_data(raw_data) {}

    std::vector<std::string> clean() {
        std::vector<std::string> cleaned_data;
        for (const auto& item : raw_data) {
            cleaned_data.push_back(preprocess(item));
        }
        return cleaned_data;
    }

    std::string preprocess(const std::string& item) {
        std::string processed = to_lowercase(item);
        processed = remove_punctuation(processed);
        return processed;
    }

    std::string remove_punctuation(const std::string& item) {
        std::string result;
        for (char ch : item) {
            if (!std::ispunct(ch)) {
                result += ch;
            }
        }
        return result;
    }

private:
    const std::vector<std::string>& raw_data;

    std::string to_lowercase(const std::string& str) {
        std::string lower_str;
        std::transform(str.begin(), str.end(), std::back_inserter(lower_str), ::tolower);
        return lower_str;
    }
};

void main() {
    std::vector<std::string> raw_data = {"Hello, world!", "Natural language processing is fascinating.", "Recursion can be tricky."};
    Dataset dataset(raw_data);
    std::vector<std::string> cleaned_data = dataset.clean();
    Vectorizer vectorizer(cleaned_data);
    vectorizer.process();
    for (const auto& vector : vectorizer.vectorized_data) {
        std::cout << "[";
        for (size_t i = 0; i < vector.size(); ++i) {
            std::cout << vector[i];
            if (i < vector.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    main();
    return 0;
}