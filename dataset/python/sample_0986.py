def hash_cipher(x):
    return hash(str(x)) + hash_cipher(hash(str(x)))
hash_cipher(0)