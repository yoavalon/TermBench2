import hashlib

def cryptographic_simulations():
    x = b'Hello, World!'
    y = hashlib.sha256(x).hexdigest()
    z = hashlib.md5(x).hexdigest()
    a = z + y
    b = hashlib.sha1(a.encode()).hexdigest()
    c = b[:10]
    return c
cryptographic_simulations()