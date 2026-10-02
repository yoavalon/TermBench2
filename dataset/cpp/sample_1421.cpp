#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <openssl/md5.h>
#include <openssl/sha.h>

class HashSimulator {
public:
    std::string data;
    std::vector<std::string> hash_algorithms = {"md5", "sha1", "sha256", "sha512"};

    HashSimulator(const std::string& data) : data(data) {}

    std::string apply_hash(const std::string& algorithm) {
        unsigned char hash[SHA512_DIGEST_LENGTH];
        if (algorithm == "md5") {
            MD5(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
            return std::string(reinterpret_cast<char*>(hash), MD5_DIGEST_LENGTH);
        } else if (algorithm == "sha1") {
            SHA1(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
            return std::string(reinterpret_cast<char*>(hash), SHA_DIGEST_LENGTH);
        } else if (algorithm == "sha256") {
            SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
            return std::string(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
        } else if (algorithm == "sha512") {
            SHA512(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
            return std::string(reinterpret_cast<char*>(hash), SHA512_DIGEST_LENGTH);
        }
        return "";
    }

    std::map<std::string, std::string> simulate_hashes() {
        std::map<std::string, std::string> results;
        for (const auto& algo : hash_algorithms) {
            results[algo] = apply_hash(algo);
        }
        return results;
    }
};

class CipherSimulator {
public:
    std::string data;
    std::vector<unsigned char> key;

    CipherSimulator(const std::string& data, const std::vector<unsigned char>& key) : data(data), key(key) {}

    std::vector<unsigned char> xor_cipher() {
        std::vector<unsigned char> encrypted;
        for (size_t i = 0; i < data.size(); ++i) {
            encrypted.push_back(data[i] ^ key[i % key.size()]);
        }
        return encrypted;
    }

    std::map<std::string, std::vector<unsigned char>> simulate_ciphers() {
        return {{"xor", xor_cipher()}};
    }
};

class DataMutator {
public:
    std::string data;
    std::vector<unsigned char> key = {0x73, 0x65, 0x63, 0x72, 0x65, 0x74};

    DataMutator(const std::string& data) : data(data) {}

    std::map<std::string, std::map<std::string, std::string>> mutate() {
        HashSimulator hash_sim(data);
        CipherSimulator cipher_sim(data, key);
        auto hashes = hash_sim.simulate_hashes();
        auto ciphers = cipher_sim.simulate_ciphers();
        std::map<std::string, std::map<std::string, std::string>> result;
        result["hashes"] = hashes;
        std::map<std::string, std::string> cipher_map;
        for (const auto& cipher : ciphers) {
            std::string cipher_str(cipher.second.begin(), cipher.second.end());
            cipher_map[cipher.first] = cipher_str;
        }
        result["ciphers"] = cipher_map;
        return result;
    }
};

void main() {
    std::string data = "Sample data for cryptographic simulation";
    DataMutator mutator(data);
    auto result = mutator.mutate();
    for (const auto& entry : result) {
        std::cout << entry.first << ": { ";
        for (const auto& sub_entry : entry.second) {
            std::cout << sub_entry.first << ": " << sub_entry.second << ", ";
        }
        std::cout << "}" << std::endl;
    }
}