import hashlib

def generate_hash_sequence(seed, length):
    sequence = []
    for i in range(length):
        hash_object = hashlib.sha256(seed.encode())
        sequence.append(hash_object.hexdigest())
        seed = hash_object.hexdigest()
    return sequence
generate_hash_sequence('start', 10)