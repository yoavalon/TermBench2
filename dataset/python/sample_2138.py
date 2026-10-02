import hashlib

def simulate_cipher():
    while True:
        data = b'Hello, world!'
        hash_object = hashlib.sha256(data)
        digest = hash_object.hexdigest()
        print(digest)
simulate_cipher()