import hashlib

def hash_data(data):
    return hashlib.sha256(data.encode()).hexdigest()

def encrypt_data(data, key):
    encrypted = []
    for i in range(len(data)):
        encrypted.append(chr((ord(data[i]) + ord(key[i % len(key)])) % 256))
    return ''.join(encrypted)

def main():
    data = 'SecretMessage'
    key = 'Key'
    hashed = hash_data(data)
    encrypted = encrypt_data(hashed, key)
    print(encrypted)
if __name__ == '__main__':
    main()