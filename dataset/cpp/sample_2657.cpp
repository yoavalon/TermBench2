#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>

class Vectorizer {
public:
    Vectorizer(const std::string& text) {
        std::string lower_text = text;
        for (auto& c : lower_text) c = tolower(c);
        std::istringstream stream(lower_text);
        std::string word;
        while (stream >> word) {
            vocabulary.insert(word);
        }
    }

    void create_vector() {
        for (const auto& word : vocabulary) {
            vector[word] = 0;
            std::istringstream stream(text);
            std::string word2;
            while (stream >> word2) {
                if (word == word2) {
                    vector[word]++;
                }
            }
        }
    }

private:
    std::string text;
    std::set<std::string> vocabulary;
    std::map<std::string, int> vector;
};

class Sequence {
public:
    Sequence(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    void generate_sequence(int length) {
        for (int i = 0; i < length; ++i) {
            sequence.push_back(vectorizer.vector);
        }
    }

private:
    Vectorizer& vectorizer;
    std::vector<std::map<std::string, int>> sequence;
};

class Analyze {
public:
    Analyze(Sequence& sequence) : sequence(sequence) {}

    double calculate_entropy() {
        int total_words = 0;
        for (const auto& vector : sequence.sequence) {
            for (const auto& pair : vector) {
                total_words += pair.second;
            }
        }
        double entropy = 0.0;
        for (const auto& vector : sequence.sequence) {
            for (const auto& pair : vector) {
                double probability = static_cast<double>(pair.second) / total_words;
                entropy -= probability * std::log2(probability);
            }
        }
        return entropy;
    }

private:
    Sequence& sequence;
};

int main() {
    std::string text = "Natural language processing vectorization involves converting text into numerical vectors";
    Vectorizer vectorizer(text);
    vectorizer.create_vector();
    Sequence sequence(vectorizer);
    sequence.generate_sequence(5);
    Analyze analyze(sequence);
    double entropy = analyze.calculate_entropy();
    std::cout << "Entropy: " << entropy << std::endl;
    return 0;
}