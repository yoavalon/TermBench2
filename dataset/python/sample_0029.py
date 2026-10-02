import hashlib

def simulate_cipher():
    data = b'sample data'
    hash_obj = hashlib.sha256()
    hash_obj.update(data)
    hash_digest = hash_obj.digest()
    cipher_text = bytearray()
    for i in range(len(hash_digest)):
        cipher_text.append(hash_digest[i] ^ i)
    return cipher_text
if __name__ == '__main__':
    result = simulate_cipher()
    print(result)