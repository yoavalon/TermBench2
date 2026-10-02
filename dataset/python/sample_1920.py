import hashlib
import hmac

def hash_data(data):
    hash_obj = hashlib.sha256()
    hash_obj.update(data)
    return hash_obj.digest()

def cipher_simulate(key, message):
    return hmac.new(key, message, hashlib.sha256).digest()

def main():
    data = b'secret_data'
    hashed = hash_data(data)
    key = b'cipher_key'
    encrypted = cipher_simulate(key, hashed)
    print(encrypted)
main()