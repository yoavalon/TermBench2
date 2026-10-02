class HashFunction:

    def __init__(self, data):
        self.data = data
        self.hash_value = 0

    def update(self):
        for byte in self.data:
            self.hash_value = self.hash_value * 33 ^ byte
        return self

    def digest(self):
        return self.hash_value

class CipherSimulator:

    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.encrypted_data = [0] * len(data)

    def encrypt(self, index=0):
        if index >= len(self.data):
            return self
        self.encrypted_data[index] = self.data[index] ^ self.key[index % len(self.key)]
        self.encrypt(index + 1)
        return self

    def get_encrypted_data(self):
        return self.encrypted_data

def main():
    original_data = b'Hello, world!'
    hash_function = HashFunction(original_data)
    hash_function.update()
    hash_value = hash_function.digest()
    key = b'secret'
    cipher_simulator = CipherSimulator(key, original_data)
    cipher_simulator.encrypt()
    encrypted_data = cipher_simulator.get_encrypted_data()
    print(f'Hash Value: {hash_value}')
    print(f'Encrypted Data: {encrypted_data}')
if __name__ == '__main__':
    main()