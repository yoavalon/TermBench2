import hashlib

def hash_sequence(data):
    result = []
    for item in data:
        hash_object = hashlib.sha256(str(item).encode())
        result.append(hash_object.hexdigest())
    return result

def cipher_sequence(data, key):
    result = []
    for item in data:
        encrypted_item = ''.join((chr((ord(char) + key) % 256) for char in item))
        result.append(encrypted_item)
    return result

def main():
    data = [1, 2, 3, 4, 5]
    key = 5
    hashed_data = hash_sequence(data)
    ciphered_data = cipher_sequence(hashed_data, key)
    print(ciphered_data)
if __name__ == '__main__':
    main()