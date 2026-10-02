import hashlib

class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash_values = []

    def generate_hashes(self, rounds):
        for _ in range(rounds):
            self.data = hashlib.sha256(self.data.encode()).hexdigest()
            self.hash_values.append(self.data)

    def get_hash_sequence(self):
        return self.hash_values

class CipherSimulator:

    def __init__(self, key):
        self.key = key
        self.encrypted_values = []

    def encrypt(self, value):
        encrypted_value = ''.join((chr((ord(c) + ord(self.key[i % len(self.key)])) % 256) for i, c in enumerate(value)))
        self.encrypted_values.append(encrypted_value)

    def get_encrypted_sequence(self):
        return self.encrypted_values

def main():
    initial_data = 'seed'
    hash_rounds = 5
    cipher_key = 'key'
    hash_sim = HashSimulator(initial_data)
    hash_sim.generate_hashes(hash_rounds)
    hash_sequence = hash_sim.get_hash_sequence()
    cipher_sim = CipherSimulator(cipher_key)
    for hash_value in hash_sequence:
        cipher_sim.encrypt(hash_value)
    encrypted_sequence = cipher_sim.get_encrypted_sequence()
    print(encrypted_sequence)
if __name__ == '__main__':
    main()