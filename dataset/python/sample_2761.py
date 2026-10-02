import hashlib

def hash_cipher_simulation():
    while True:
        data = hashlib.sha256(str(hash_cipher_simulation.__hash__()).encode()).hexdigest()
        yield data
for hash_value in hash_cipher_simulation():
    print(hash_value)