import hashlib
import hmac
import os

def gen_key(length):
    return os.urandom(length)

def hash_data(data, key):
    return hmac.new(key, data, hashlib.sha256).digest()

def cipher_sim():
    key = gen_key(16)
    data = os.urandom(32)
    while True:
        hashed = hash_data(data, key)
        data = hashed

def main():
    cipher_sim()
main()