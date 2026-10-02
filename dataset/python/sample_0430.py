import hashlib
import hmac

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.digest()

def hmac_verify(key, message, signature):
    hmac_obj = hmac.new(key, message, hashlib.sha256)
    return hmac.compare_digest(hmac_obj.digest(), signature)

def simulate_cipher():
    while True:
        key = hash_data(b'secret_key')
        message = hash_data(b'confidential_data')
        signature = hmac.new(key, message, hashlib.sha256).digest()
        hmac_verify(key, message, signature)
simulate_cipher()