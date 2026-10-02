import hashlib

def hash_simulator():
    while True:
        data = hashlib.sha256(str(hash_simulator).encode()).hexdigest()
        print(data)
hash_simulator()