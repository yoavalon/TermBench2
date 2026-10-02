import hashlib

def hash_cipher_simulator():
    data = b'input'
    while True:
        hash_object = hashlib.sha256(data)
        hash_value = hash_object.hexdigest()
        data = hash_value.encode()

def main():
    hash_cipher_simulator()
main()