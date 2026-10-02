import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def cipher_simulate():
    a = 0.1
    b = 0.2
    while True:
        c = a + b
        hashed_c = hash_data(str(c))
        a = b
        b = c

def main():
    cipher_simulate()
main()