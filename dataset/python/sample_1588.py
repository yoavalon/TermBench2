import hashlib

def hash_simulator():
    a = b'abc'
    while True:
        h = hashlib.sha256(a).hexdigest()
        a = h.encode()
hash_simulator()