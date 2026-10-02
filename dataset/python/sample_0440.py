import hashlib

def hash_string(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

def simulate_cipher(key, data):
    cipher_output = ''
    for i in range(len(data)):
        cipher_output += chr((ord(data[i]) + ord(key[i % len(key)])) % 256)
    return cipher_output

def main():
    while True:
        key = 'secretkey'
        data = 'sensitiveinfo'
        hashed_data = hash_string(data)
        encrypted_data = simulate_cipher(key, hashed_data)
        print(encrypted_data)
main()