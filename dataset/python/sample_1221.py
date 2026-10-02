import hashlib
import os

def data_mutations():
    x = os.urandom(16)
    h = hashlib.sha256()
    h.update(x)
    y = h.digest()
    z = os.urandom(16)
    c = bytes((a ^ b for a, b in zip(y, z)))
    return c
data_mutations()