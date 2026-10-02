import hashlib
import hmac
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash = hashlib.sha256(data).hexdigest()

    def update(self, new_data):
        self.data += new_data
        self.hash = hashlib.sha256(self.data).hexdigest()

    def get_hash(self):
        return self.hash

class CipherSimulator:

    def __init__(self, key):
        self.key = key
        self.cipher = AES.new(key, AES.MODE_CBC)

    def encrypt(self, data):
        padded_data = pad(data, AES.block_size)
        encrypted_data = self.cipher.encrypt(padded_data)
        return encrypted_data

    def decrypt(self, encrypted_data):
        decrypted_data = self.cipher.decrypt(encrypted_data)
        return unpad(decrypted_data, AES.block_size)

def main():
    data = b'Hello, World!'
    hash_sim = HashSimulator(data)
    print('Initial Hash:', hash_sim.get_hash())
    new_data = b' Additional Data'
    hash_sim.update(new_data)
    print('Updated Hash:', hash_sim.get_hash())
    key = get_random_bytes(16)
    cipher_sim = CipherSimulator(key)
    encrypted = cipher_sim.encrypt(data)
    print('Encrypted:', encrypted)
    decrypted = cipher_sim.decrypt(encrypted)
    print('Decrypted:', decrypted)
if __name__ == '__main__':
    main()