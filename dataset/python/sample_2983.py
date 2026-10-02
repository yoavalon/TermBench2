import hashlib

class HashSequence:

    def __init__(self, initial_value):
        self.current_value = initial_value

    def update(self):
        hash_object = hashlib.sha256()
        hash_object.update(self.current_value.encode())
        self.current_value = hash_object.hexdigest()
        return self.current_value

class CipherSimulator:

    def __init__(self, hash_sequence):
        self.hash_sequence = hash_sequence

    def encrypt(self):
        encrypted_value = ''
        for char in self.hash_sequence.current_value:
            encrypted_value += chr((ord(char) + 3) % 256)
        return encrypted_value

class SequenceAnalyzer:

    def __init__(self, cipher_simulator):
        self.cipher_simulator = cipher_simulator

    def analyze(self):
        while True:
            hashed_value = self.cipher_simulator.hash_sequence.update()
            encrypted_value = self.cipher_simulator.encrypt()
            print(f'Hashed: {hashed_value}\nEncrypted: {encrypted_value}\n')

def main():
    initial_value = 'seed_value'
    hash_sequence = HashSequence(initial_value)
    cipher_simulator = CipherSimulator(hash_sequence)
    sequence_analyzer = SequenceAnalyzer(cipher_simulator)
    sequence_analyzer.analyze()
main()