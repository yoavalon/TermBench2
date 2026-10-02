def hash_simulate(data, depth):
    if depth == 0:
        return data
    else:
        return hash_simulate(hash(data) ^ depth, depth - 1)

def cipher_decrypt(ciphertext, key, rounds):
    if rounds == 0:
        return ciphertext
    else:
        return cipher_decrypt(ciphertext ^ key, key, rounds - 1)

def main():
    initial_data = 12345
    hash_depth = 5
    cipher_key = 6789
    cipher_rounds = 3
    hashed_data = hash_simulate(initial_data, hash_depth)
    decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds)
    print(decrypted_data)
main()