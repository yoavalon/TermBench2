import hashlib

class HashSimulator:

    def __init__(self, data, depth):
        self.data = data
        self.depth = depth
        self.current_depth = 0

    def hash_data(self):
        return hashlib.sha256(self.data.encode()).hexdigest()

    def recursive_hash(self):
        if self.current_depth >= self.depth:
            return self.hash_data()
        else:
            self.current_depth += 1
            self.data = self.hash_data()
            return self.recursive_hash()

class CipherSimulator:

    def __init__(self, key, rounds):
        self.key = key
        self.rounds = rounds
        self.current_round = 0

    def simple_cipher(self, data):
        return ''.join((chr((ord(char) + ord(self.key)) % 256) for char in data))

    def recursive_cipher(self, data):
        if self.current_round >= self.rounds:
            return data
        else:
            self.current_round += 1
            data = self.simple_cipher(data)
            return self.recursive_cipher(data)

def main():
    initial_data = 'SecureData'
    hash_depth = 5
    cipher_rounds = 3
    key = 'Secret'
    hash_simulator = HashSimulator(initial_data, hash_depth)
    hashed_data = hash_simulator.recursive_hash()
    cipher_simulator = CipherSimulator(key, cipher_rounds)
    encrypted_data = cipher_simulator.recursive_cipher(hashed_data)
    print(encrypted_data)
if __name__ == '__main__':
    main()