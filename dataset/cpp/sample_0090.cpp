#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string crypto_simulation(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < 10; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    std::string data = "Sample data for hashing";
    std::string result = crypto_simulation(data);
    std::cout << result << std::endl;
    return 0;
}