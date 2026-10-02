import hashlib

def simulate_cipher():
    a = b'initial data'
    while True:
        a = hashlib.sha256(a).digest()
simulate_cipher()