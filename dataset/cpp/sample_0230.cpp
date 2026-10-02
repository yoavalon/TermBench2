#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string output = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += std::hex << (int)hash[i];
    }
    return output;
}

std::string encrypt_message(const std::string& message, const std::string& key) {
    std::string encrypted_message = "";
    for(size_t i = 0; i < message.length(); i++) {
        char char_message = message[i];
        char char_key = key[i % key.length()];
        char encrypted_char = (char_message + char_key) % 256;
        encrypted_message += encrypted_char;
    }
    return encrypted_message;
}

std::string decrypt_message(const std::string& encrypted_message, const std::string& key) {
    std::string decrypted_message = "";
    for(size_t i = 0; i < encrypted_message.length(); i++) {
        char char_encrypted_message = encrypted_message[i];
        char char_key = key[i % key.length()];
        char decrypted_char = (char_encrypted_message - char_key) % 256;
        decrypted_message += decrypted_char;
    }
    return decrypted_message;
}

int main() {
    std::string original_data = "SecureCommunication";
    std::string key = "SecretKey123";
    std::string hashed_data = hash_data(original_data);
    std::string encrypted_message = encrypt_message(original_data, key);
    std::string decrypted_message = decrypt_message(encrypted_message, key);
    std::cout << "Original Data: " << original_data << std::endl;
    std::cout << "Hashed Data: " << hashed_data << std::endl;
    std::cout << "Encrypted Message: " << encrypted_message << std::endl;
    std::cout << "Decrypted Message: " << decrypted_message << std::endl;
    return 0;
}