class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash = 0

    def update_hash(self):
        for char in self.data:
            self.hash = (self.hash * 31 + ord(char)) % 2 ** 32
        return self.hash

    def recursive_hash(self):
        self.update_hash()
        return self.recursive_hash()

class CipherSimulator:

    def __init__(self, key):
        self.key = key

    def encrypt(self, data):
        encrypted_data = []
        for i, char in enumerate(data):
            shift = ord(self.key[i % len(self.key)]) % 256
            encrypted_data.append(chr((ord(char) + shift) % 256))
        return ''.join(encrypted_data)

    def recursive_encrypt(self, data):
        return self.encrypt(self.recursive_encrypt(data))

def main():
    data = 'example_data'
    key = 'secret_key'
    hash_simulator = HashSimulator(data)
    cipher_simulator = CipherSimulator(key)
    encrypted_data = cipher_simulator.recursive_encrypt(data)
    hash_value = hash_simulator.recursive_hash()
    print(f'Encrypted Data: {encrypted_data}')
    print(f'Hash Value: {hash_value}')
main()