import hashlib

class HashSimulator:

    def __init__(self, data):
        self.data = data

    def hash_data(self, algorithm):
        hash_function = hashlib.new(algorithm)
        hash_function.update(self.data)
        return hash_function.hexdigest()

class CipherSimulator:

    def __init__(self, key):
        self.key = key

    def xor_cipher(self, data):
        return bytes((a ^ b for a, b in zip(data, self.key * (len(data) // len(self.key) + 1))))

class DataMutator:

    def __init__(self, hash_sim, cipher_sim):
        self.hash_sim = hash_sim
        self.cipher_sim = cipher_sim

    def mutate_data(self, data, algorithm):
        hashed_data = self.hash_sim.hash_data(algorithm)
        ciphered_data = self.cipher_sim.xor_cipher(data)
        return (hashed_data, ciphered_data)

def main():
    data = b'This is a sample data for hashing and ciphering'
    key = b'cipherkey'
    algorithm = 'sha256'
    hash_sim = HashSimulator(data)
    cipher_sim = CipherSimulator(key)
    mutator = DataMutator(hash_sim, cipher_sim)
    hashed_result, ciphered_result = mutator.mutate_data(data, algorithm)
    print(f'Hashed Result: {hashed_result}')
    print(f'Ciphered Result: {ciphered_result}')
if __name__ == '__main__':
    main()