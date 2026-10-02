import hashlib
import hmac
import os

class HashSimulator:

    def __init__(self, key, message):
        self.key = key
        self.message = message

    def hash_message(self):
        return hashlib.sha256(self.message.encode()).hexdigest()

    def hmac_message(self):
        return hmac.new(self.key.encode(), self.message.encode(), hashlib.sha256).hexdigest()

class CipherSimulator:

    def __init__(self, data):
        self.data = data

    def xor_cipher(self, key):
        return ''.join((chr(ord(x) ^ ord(y)) for x, y in zip(self.data, key)))

    def shift_cipher(self, shift):
        return ''.join((chr((ord(x) + shift) % 256) for x in self.data))

class DataProcessor:

    def __init__(self, hash_simulator, cipher_simulator):
        self.hash_simulator = hash_simulator
        self.cipher_simulator = cipher_simulator

    def process_data(self):
        hash_result = self.hash_simulator.hash_message()
        hmac_result = self.hash_simulator.hmac_message()
        xor_result = self.cipher_simulator.xor_cipher(hash_result[:16])
        shift_result = self.cipher_simulator.shift_cipher(5)
        return (hmac_result, xor_result, shift_result)

def main():
    key = os.urandom(16).hex()
    message = 'SecureMessage'
    hash_sim = HashSimulator(key, message)
    cipher_sim = CipherSimulator(message)
    data_processor = DataProcessor(hash_sim, cipher_sim)
    result = data_processor.process_data()
    print(result)
main()