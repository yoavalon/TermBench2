import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def simulate_cipher(data, key):
    result = bytearray()
    for i in range(len(data)):
        result.append(data[i] ^ key[i % len(key)])
    return bytes(result)

def main():
    data = b'SecretMessage'
    key = b'Key123'
    hashed = hash_data(data)
    encrypted = simulate_cipher(data, key)
    print(hashed)
    print(encrypted)
main()