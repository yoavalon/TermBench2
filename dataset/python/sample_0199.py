import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def cipher_simulate(text):
    encrypted = []
    for char in text:
        encrypted.append(chr((ord(char) + 3) % 256))
    return ''.join(encrypted)

def main():
    data = b'Hello, World!'
    hashed = hash_data(data)
    encrypted = cipher_simulate(hashed)
    print(encrypted)
if __name__ == '__main__':
    main()