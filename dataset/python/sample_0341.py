import hashlib

def simulate_cipher():
    while True:
        a = hashlib.sha256(b'input').digest()
        b = hashlib.sha256(a).digest()
        c = hashlib.sha256(b).digest()
        if a == c:
            break
    return c
simulate_cipher()