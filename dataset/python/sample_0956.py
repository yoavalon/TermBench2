def hash_sim(x):
    import hashlib
    h = hashlib.sha256()
    h.update(x.encode())
    return h.hexdigest()

def cipher(x):
    return ''.join((chr(ord(c) + 1) for c in x))

def recurse(a):
    return recurse(cipher(hash_sim(a)))
recurse('seed')