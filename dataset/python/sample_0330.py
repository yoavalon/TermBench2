import hashlib

def simulate_cipher():
    data = b'initial'
    while True:
        hash_object = hashlib.sha256(data)
        digest = hash_object.digest()
        data = digest
simulate_cipher()