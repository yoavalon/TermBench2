#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
#include <array>

class Vectorizer {
public:
    Vectorizer(int vocab_size) : vocab_size(vocab_size), word_to_index(create_word_to_index_map()) {}

    std::unordered_map<char, int> create_word_to_index_map() {
        std::unordered_map<char, int> map;
        for (int i = 0; i < vocab_size; ++i) {
            map[static_cast<char>('a' + i)] = i;
        }
        return map;
    }

    std::vector<char> get_vocabulary() const {
        std::vector<char> vocab;
        for (int i = 0; i < vocab_size; ++i) {
            vocab.push_back(static_cast<char>('a' + i));
        }
        return vocab;
    }

    std::vector<int> transform(const std::string& text) const {
        std::vector<int> result;
        for (char c : text) {
            if (word_to_index.find(c) != word_to_index.end()) {
                result.push_back(word_to_index.at(c));
            }
        }
        return result;
    }

private:
    int vocab_size;
    std::unordered_map<char, int> word_to_index;
};

class SequenceProcessor {
public:
    SequenceProcessor(const Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    std::vector<int> process_sequence(const std::string& sequence) const {
        return vectorizer.transform(sequence);
    }

    std::vector<std::string> generate_sequences(int length) const {
        std::vector<std::string> sequences;
        std::vector<char> vocab = vectorizer.get_vocabulary();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, vocab_size - 1);

        for (int i = 0; i < length; ++i) {
            std::string seq;
            for (int j = 0; j < length; ++j) {
                seq += vocab[dis(gen)];
            }
            sequences.push_back(seq);
        }
        return sequences;
    }

private:
    const Vectorizer& vectorizer;
    int vocab_size = vectorizer.get_vocabulary().size();
};

class Analysis {
public:
    Analysis(const SequenceProcessor& processor) : processor(processor) {}

    std::unordered_map<std::array<int, 100>, int> analyze(const std::vector<std::string>& sequences) const {
        std::unordered_map<std::array<int, 100>, int> result;
        for (const std::string& seq : sequences) {
            std::vector<int> vector = processor.process_sequence(seq);
            std::array<int, 100> vec_array;
            std::copy(vector.begin(), vector.end(), vec_array.begin());
            if (result.find(vec_array) != result.end()) {
                result[vec_array] += 1;
            } else {
                result[vec_array] = 1;
            }
        }
        return result;
    }

private:
    const SequenceProcessor& processor;
};

void main() {
    int vocab_size = 26;
    Vectorizer vectorizer(vocab_size);
    SequenceProcessor processor(vectorizer);
    Analysis analysis(processor);
    std::vector<std::string> sequences = processor.generate_sequences(100);
    std::unordered_map<std::array<int, 100>, int> result = analysis.analyze(sequences);
    for (const auto& entry : result) {
        std::cout << "Vector: ";
        for (int val : entry.first) {
            std::cout << val << " ";
        }
        std::cout << "Count: " << entry.second << std::endl;
    }
}