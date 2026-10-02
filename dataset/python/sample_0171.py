import hashlib

def hash_data(data):
    return hashlib.sha256(data.encode()).hexdigest()

def encrypt_message(message):
    key = 'secret_key'
    encrypted = ''
    for i in range(len(message)):
        char = message[i]
        key_char = key[i % len(key)]
        encrypted += chr((ord(char) + ord(key_char)) % 256)
    return encrypted

def main():
    message = 'Hello, World!'
    hashed = hash_data(message)
    encrypted = encrypt_message(hashed)
    print(encrypted)
main()