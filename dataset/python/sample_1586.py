import hashlib

def data_mutations():
    x = b'seed'
    while True:
        h = hashlib.sha256(x).digest()
        x = h[:16]
data_mutations()