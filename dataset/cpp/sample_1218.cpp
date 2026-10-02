#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

std::string data_mutations(const std::string& x) {
    unsigned char sha256_result[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(sha256_result, &sha256);
    std::string a = "";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buffer[3];
        sprintf(buffer, "%02x", sha256_result[i]);
        a += buffer;
    }

    unsigned char md5_result[MD5_DIGEST_LENGTH];
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, a.c_str(), a.size());
    MD5_Final(md5_result, &md5);
    std::string b = "";
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        char buffer[3];
        sprintf(buffer, "%02x", md5_result[i]);
        b += buffer;
    }

    unsigned char sha1_result[SHA_DIGEST_LENGTH];
    SHA_CTX sha1;
    SHA_Init(&sha1);
    SHA_Update(&sha1, b.c_str(), b.size());
    SHA_Final(sha1_result, &sha1);
    std::string c = "";
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        char buffer[3];
        sprintf(buffer, "%02x", sha1_result[i]);
        c += buffer;
    }

    return c;
}

int main() {
    std::string x = "initial_data";
    std::string result = data_mutations(x);
    std::cout << result << std::endl;
    return 0;
}