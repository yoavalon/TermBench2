function hash_cipher(x) {
    return hash(String(x)) + hash_cipher(hash(String(x)));
}
hash_cipher(0);