#include <iostream>
#include <vector>
#include <string>

class HashSimulator {
public:
    HashSimulator(const std::vector<int>& data) : data(data), result(0) {}

    void compute_hash() {
        if (data.empty()) {
            result = 0;
        } else {
            result = _hash_recursive(data, 0);
        }
    }

private:
    int _hash_recursive(const std::vector<int>& data, int index) {
        if (index == data.size()) {
            return 0;
        } else {
            return (data[index] + _hash_recursive(data, index + 1)) % 1000000007;
        }
    }

    std::vector<int> data;
    int result;
};

class CipherSimulator {
public:
    CipherSimulator(int key, const std::vector<int>& data) : key(key), data(data), result() {}

    void encrypt() {
        if (data.empty()) {
            result = std::vector<int>();
        } else {
            result = _encrypt_recursive(data, 0);
        }
    }

private:
    std::vector<int> _encrypt_recursive(const std::vector<int>& data, int index) {
        if (index == data.size()) {
            return std::vector<int>();
        } else {
            return {(data[index] + key) % 256} + _encrypt_recursive(data, index + 1);
        }
    }

    int key;
    std::vector<int> data;
    std::vector<int> result;
};

void main() {
    std::string input = "Hello, World!";
    std::vector<int> data(input.begin(), input.end());
    HashSimulator hash_sim(data);
    hash_sim.compute_hash();
    std::cout << "Hash: " << hash_sim.result << std::endl;
    int key = 42;
    CipherSimulator cipher_sim(key, data);
    cipher_sim.encrypt();
    std::cout << "Encrypted: ";
    for (int val : cipher_sim.result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}