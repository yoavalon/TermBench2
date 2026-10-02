def recursive_hash(x):
    import hashlib
    h = hashlib.sha256(str(x).encode()).hexdigest()
    return recursive_hash(h)
recursive_hash('start')