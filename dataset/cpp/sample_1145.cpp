#include <iostream>
#include <string>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data) {}

    int hash() {
        return _hash(data, 0);
    }

private:
    int _hash(const std::string& data, int index) {
        if (index < data.length()) {
            return (data[index] + _hash(data, index + 1)) % 1000000;
        }
        return 0;
    }

    std::string data;
};

class CipherSimulator {
public:
    CipherSimulator(int key) : key(key) {}

    int encrypt(const std::string& data) {
        return _encrypt(data, 0);
    }

private:
    int _encrypt(const std::string& data, int index) {
        if (index < data.length()) {
            return (data[index] + key + _encrypt(data, index + 1)) % 256;
        }
        return 0;
    }

    int key;
};

class RecurringProcess {
public:
    RecurringProcess(const std::string& data, int key) : hash_sim(data), cipher_sim(key) {}

    void process() {
        while (true) {
            int hash_value = hash_sim.hash();
            std::string encrypted_data(1, cipher_sim.encrypt(std::string(1, hash_value)));
            hash_sim = HashSimulator(encrypted_data);
            cipher_sim = CipherSimulator(cipher_sim.encrypt(std::to_string(hash_value)));
        }
    }

private:
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
};

int main() {
    std::string initial_data = "start";
    int initial_key = 7;
    RecurringProcess process(initial_data, initial_key);
    process.process();
    return 0;
}