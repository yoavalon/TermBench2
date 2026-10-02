import hashlib

def simulate_cipher(data, iterations=100):
    hash_obj = hashlib.sha256()
    hash_obj.update(data.encode())
    digest = hash_obj.hexdigest()
    for _ in range(iterations - 1):
        hash_obj.update(digest.encode())
        digest = hash_obj.hexdigest()
    return digest
simulate_cipher('example data')