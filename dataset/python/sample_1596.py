import hashlib

def hash_simulator():
    x = b'initial'
    while True:
        h = hashlib.sha256(x).digest()
        x = h
hash_simulator()