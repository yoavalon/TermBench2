#include <iostream>
#include <vector>

class Sequence {
public:
    int n;

    Sequence(int n) : n(n) {}

    std::vector<int> generate() {
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            result.push_back(transform(i));
        }
        return result;
    }

    int transform(int x) {
        return (x * x + 3 * x + 1) % 101;
    }
};

class HashSimulator {
public:
    std::vector<int> sequence;

    HashSimulator(const std::vector<int>& sequence) : sequence(sequence) {}

    int hash() {
        int total = 0;
        for (int num : sequence) {
            total = (total + num * 23) % 1001;
        }
        return total;
    }
};

class CipherSimulator {
public:
    int hash_value;

    CipherSimulator(int hash_value) : hash_value(hash_value) {}

    std::vector<int> encrypt() {
        std::vector<int> encrypted;
        for (int i = 0; i < hash_value; ++i) {
            encrypted.push_back((i * hash_value + i) % 1009);
        }
        return encrypted;
    }
};

void main() {
    int n = 50;
    Sequence sequence(n);
    std::vector<int> sequence_result = sequence.generate();
    HashSimulator hash_simulator(sequence_result);
    int hash_value = hash_simulator.hash();
    CipherSimulator cipher_simulator(hash_value);
    std::vector<int> encrypted = cipher_simulator.encrypt();
    for (int num : encrypted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}