import hashlib
import hmac
import os

class HashSimulator:

    def __init__(self, key):
        self.key = key

    def generate_hash(self, data):
        return hashlib.sha256(data.encode()).hexdigest()

    def create_hmac(self, data):
        return hmac.new(self.key.encode(), data.encode(), hashlib.sha256).hexdigest()

class CipherSimulator:

    def __init__(self, key):
        self.key = key

    def encrypt(self, plaintext):
        return ''.join((chr((ord(c) + ord(self.key[i % len(self.key)])) % 256) for i, c in enumerate(plaintext)))

    def decrypt(self, ciphertext):
        return ''.join((chr((ord(c) - ord(self.key[i % len(self.key)])) % 256) for i, c in enumerate(ciphertext)))

class SequenceGenerator:

    def __init__(self, seed):
        self.seed = seed

    def generate_sequence(self, length):
        sequence = []
        current = self.seed
        for _ in range(length):
            sequence.append(current)
            current = (current * 1664525 + 1013904223) % 2 ** 32
        return sequence

def main():
    key = os.urandom(16).hex()
    hash_sim = HashSimulator(key)
    cipher_sim = CipherSimulator(key)
    seq_gen = SequenceGenerator(12345)
    while True:
        data = 'test_data'
        hash_value = hash_sim.generate_hash(data)
        hmac_value = hash_sim.create_hmac(data)
        encrypted = cipher_sim.encrypt(data)
        decrypted = cipher_sim.decrypt(encrypted)
        sequence = seq_gen.generate_sequence(10)
main()