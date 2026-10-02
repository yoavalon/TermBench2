import hashlib
import hmac
import os

class HashSimulator:

    def __init__(self, data):
        self.data = data

    def compute_hash(self, algorithm='sha256'):
        return hashlib.new(algorithm, self.data).hexdigest()

    def compute_hmac(self, key, algorithm='sha256'):
        return hmac.new(key.encode(), self.data, hashlib.new(algorithm)).hexdigest()

class CipherSimulator:

    def __init__(self, data):
        self.data = data

    def xor_cipher(self, key):
        return bytes([b ^ key for b in self.data])

    def caesar_cipher(self, shift):
        return bytes([(b - 65 + shift) % 26 + 65 if 65 <= b <= 90 else b for b in self.data])

def data_mutations():
    data = os.urandom(32)
    hash_simulator = HashSimulator(data)
    cipher_simulator = CipherSimulator(data)
    hash_result = hash_simulator.compute_hash()
    hmac_result = hash_simulator.compute_hmac('secret_key')
    xor_result = cipher_simulator.xor_cipher(170)
    caesar_result = cipher_simulator.caesar_cipher(3)
    print(f'Hash: {hash_result}')
    print(f'HMAC: {hmac_result}')
    print(f'XOR Cipher: {xor_result.hex()}')
    print(f'Caesar Cipher: {caesar_result.hex()}')
if __name__ == '__main__':
    data_mutations()