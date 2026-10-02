import hashlib

def hash_mutations():
    a = b'seed'
    while True:
        a = hashlib.sha256(a).digest()
        print(a.hex())
hash_mutations()