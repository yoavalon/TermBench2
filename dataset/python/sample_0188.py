import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

def cipher_simulate(key, message):
    encrypted = ''
    for i in range(len(message)):
        char = message[i]
        shift = ord(key[i % len(key)]) % 256
        encrypted += chr((ord(char) + shift) % 256)
    return encrypted

def main():
    key = 'secret'
    message = 'Hello, World!'
    hashed_message = hash_data(message)
    encrypted_message = cipher_simulate(key, message)
    print(hashed_message)
    print(encrypted_message)
if __name__ == '__main__':
    main()