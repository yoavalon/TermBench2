import hashlib

def generate_hash(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

def simulate_cipher(hash_val):
    key = b'secret'
    cipher_text = bytearray()
    for i in range(len(hash_val)):
        byte = int(hash_val[i:i + 2], 16) ^ key[i % len(key)]
        cipher_text.append(byte)
    return cipher_text.hex()

def main():
    data = 'secure_message'
    hash_val = generate_hash(data)
    cipher_text = simulate_cipher(hash_val)
    print(cipher_text)
main()