import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

def simulate_cipher(data):
    key = 'secret_key'
    encrypted = ''
    for i in range(len(data)):
        char = data[i]
        key_char = key[i % len(key)]
        encrypted += chr((ord(char) + ord(key_char)) % 256)
    return encrypted

def main():
    data = 'Hello, World!'
    hashed = hash_data(data)
    ciphered = simulate_cipher(hashed)
    print(ciphered)
if __name__ == '__main__':
    main()