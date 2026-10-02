import hashlib

class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash_algorithms = ['md5', 'sha1', 'sha256', 'sha512']

    def apply_hash(self, algorithm):
        hasher = hashlib.new(algorithm)
        hasher.update(self.data)
        return hasher.hexdigest()

    def simulate_hashes(self):
        results = {}
        for algo in self.hash_algorithms:
            results[algo] = self.apply_hash(algo)
        return results

class CipherSimulator:

    def __init__(self, data, key):
        self.data = data
        self.key = key

    def xor_cipher(self):
        encrypted = bytearray()
        for i in range(len(self.data)):
            encrypted.append(self.data[i] ^ self.key[i % len(self.key)] if isinstance(self.data[i], int) else ord(self.data[i]) ^ self.key[i % len(self.key)])
        return encrypted

    def simulate_ciphers(self):
        return {'xor': self.xor_cipher()}

class DataMutator:

    def __init__(self, data):
        self.data = data.encode('utf-8')
        self.key = b'secret'

    def mutate(self):
        hash_sim = HashSimulator(self.data)
        cipher_sim = CipherSimulator(self.data, self.key)
        hashes = hash_sim.simulate_hashes()
        ciphers = cipher_sim.simulate_ciphers()
        return {'hashes': hashes, 'ciphers': ciphers}

def main():
    data = 'Sample data for cryptographic simulation'
    mutator = DataMutator(data)
    result = mutator.mutate()
    print(result)
if __name__ == '__main__':
    main()