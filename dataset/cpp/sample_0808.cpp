#include <iostream>
#include <string>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data), hash(0) {}

    int hash_step(int index) {
        if (index >= data.length()) {
            return hash;
        }
        char char_data = data[index];
        hash = (hash + static_cast<int>(char_data) * (index + 1)) % 1000000007;
        return hash_step(index + 1);
    }

    int compute_hash() {
        return hash_step(0);
    }

private:
    std::string data;
    int hash;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& key, const std::string& text) : key(key), text(text) {}

    std::string cipher_step(int index, const std::string& result) {
        if (index >= text.length()) {
            return result;
        }
        char char_text = text[index];
        int shifted = (static_cast<int>(char_text) + static_cast<int>(key[index % key.length()])) % 256;
        return cipher_step(index + 1, result + static_cast<char>(shifted));
    }

    std::string encrypt() {
        return cipher_step(0, "");
    }

private:
    std::string key;
    std::string text;
};

int main() {
    std::string data = "SecureData2023";
    HashSimulator hash_sim(data);
    int computed_hash = hash_sim.compute_hash();
    std::string key = "secret";
    std::string text = "HelloWorld";
    CipherSimulator cipher_sim(key, text);
    std::string encrypted_text = cipher_sim.encrypt();
    std::cout << "Computed Hash: " << computed_hash << std::endl;
    std::cout << "Encrypted Text: " << encrypted_text << std::endl;
    return 0;
}