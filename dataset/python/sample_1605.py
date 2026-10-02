import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def cipher_simulate(hash_result):
    key = b'secret_key'
    cipher_text = bytearray()
    for i in range(len(hash_result)):
        cipher_text.append(hash_result[i] ^ key[i % len(key)])
    return bytes(cipher_text)

def main():
    while True:
        data = b'sensitive_data'
        hashed = hash_data(data)
        ciphered = cipher_simulate(hashed.encode())
        print(ciphered)
main()