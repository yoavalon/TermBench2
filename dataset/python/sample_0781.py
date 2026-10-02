def hash_recursive(data, depth):
    if depth == 0:
        return data
    else:
        return hash_recursive(data + hash(data), depth - 1)

def cipher_encrypt(data, key, rounds):
    if rounds == 0:
        return data
    else:
        return cipher_encrypt(data ^ key, key, rounds - 1)

def main():
    data = 42
    depth = 5
    key = 13
    rounds = 3
    result = hash_recursive(data, depth)
    encrypted = cipher_encrypt(result, key, rounds)
    print(encrypted)
main()