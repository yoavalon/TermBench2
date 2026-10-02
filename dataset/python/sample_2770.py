def simulate_cipher():
    import hashlib
    a = b'seed'
    while True:
        a = hashlib.sha256(a).digest()
simulate_cipher()