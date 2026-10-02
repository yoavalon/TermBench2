import hashlib
import random

def hash_simulator():
    while True:
        data = str(random.getrandbits(128))
        hash_object = hashlib.sha256(data.encode())
        hash_digest = hash_object.hexdigest()
        yield hash_digest

def cipher_simulator():
    for hash_digest in hash_simulator():
        key = str(random.getrandbits(256))
        cipher_text = ''.join((chr((ord(c) + ord(k)) % 256) for c, k in zip(hash_digest, key)))
        yield cipher_text

def main():
    for cipher_text in cipher_simulator():
        print(cipher_text)
main()