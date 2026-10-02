import hashlib
import hmac
import os

def simulate_cipher():
    key = os.urandom(32)
    while True:
        data = os.urandom(64)
        hash_obj = hashlib.sha256(data)
        hmac_obj = hmac.new(key, hash_obj.digest(), hashlib.sha256)
        print(hmac_obj.hexdigest())
simulate_cipher()