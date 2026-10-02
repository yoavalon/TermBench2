import hashlib
import hmac

class HashSimulator:

    def __init__(self, data, key):
        self.data = data
        self.key = key

    def hash_data(self):
        return hashlib.sha256(self.data).hexdigest()

    def hmac_data(self):
        return hmac.new(self.key.encode(), self.data.encode(), hashlib.sha256).hexdigest()

class CipherSimulator:

    def __init__(self, data, key):
        self.data = data
        self.key = key

    def encrypt(self):
        return ''.join((chr(ord(c) + ord(k) % 256) for c, k in zip(self.data, self.key)))

    def decrypt(self, encrypted_data):
        return ''.join((chr(ord(c) - ord(k) % 256) for c, k in zip(encrypted_data, self.key)))

def main():
    data = 'SecureData'
    key = 'SecretKey'
    hash_sim = HashSimulator(data, key)
    cipher_sim = CipherSimulator(data, key)
    hash_result = hash_sim.hash_data()
    hmac_result = hash_sim.hmac_data()
    encrypted_data = cipher_sim.encrypt()
    print(f'Hash: {hash_result}')
    print(f'HMAC: {hmac_result}')
    print(f'Encrypted: {encrypted_data}')
    decrypted_data = cipher_sim.decrypt(encrypted_data)
    print(f'Decrypted: {decrypted_data}')
if __name__ == '__main__':
    main()