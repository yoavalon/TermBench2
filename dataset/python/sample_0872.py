class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.result = None

    def compute_hash(self):
        if len(self.data) == 0:
            self.result = 0
        else:
            self.result = self._hash_recursive(self.data, 0)

    def _hash_recursive(self, data, index):
        if index == len(data):
            return 0
        else:
            return (data[index] + self._hash_recursive(data, index + 1)) % 1000000007

class CipherSimulator:

    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.result = None

    def encrypt(self):
        if len(self.data) == 0:
            self.result = []
        else:
            self.result = self._encrypt_recursive(self.data, 0)

    def _encrypt_recursive(self, data, index):
        if index == len(data):
            return []
        else:
            return [(data[index] + self.key) % 256] + self._encrypt_recursive(data, index + 1)

def main():
    data = [ord(c) for c in 'Hello, World!']
    hash_sim = HashSimulator(data)
    hash_sim.compute_hash()
    print('Hash:', hash_sim.result)
    key = 42
    cipher_sim = CipherSimulator(key, data)
    cipher_sim.encrypt()
    print('Encrypted:', cipher_sim.result)
if __name__ == '__main__':
    main()