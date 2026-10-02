import hashlib
import hmac
import os

class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash_function = hashlib.sha256

    def generate_hash(self):
        return self.hash_function(self.data).hexdigest()

    def generate_hmac(self, key):
        return hmac.new(key, self.data, self.hash_function).hexdigest()

class CipherSimulator:

    def __init__(self, data, key):
        self.data = data
        self.key = key

    def encrypt(self):
        return bytes([a ^ b for a, b in zip(self.data, self.key * (len(self.data) // len(self.key) + 1))])

    def decrypt(self):
        return self.encrypt()

def main():
    data = os.urandom(32)
    key = os.urandom(16)
    hash_sim = HashSimulator(data)
    hmac_sim = CipherSimulator(hash_sim.generate_hash().encode(), key)
    encrypted_hmac = hmac_sim.encrypt()
    decrypted_hmac = hmac_sim.decrypt()
    print('Original HMAC:', hash_sim.generate_hmac(key))
    print('Encrypted HMAC:', encrypted_hmac.hex())
    print('Decrypted HMAC:', decrypted_hmac.hex())
if __name__ == '__main__':
    main()