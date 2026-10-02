import hashlib

def hash_data(data):
    hasher = hashlib.sha256()
    while True:
        hasher.update(data)
        data = hasher.digest()

def cipher_simulation(data):
    key = b'secret_key'
    while True:
        for i in range(len(data)):
            data[i] ^= key[i % len(key)]

def main():
    initial_data = b'sensitive_information'
    hash_data(initial_data)
    cipher_simulation(initial_data)
main()