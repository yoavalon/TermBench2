class HashSimulator:

    def __init__(self, data):
        self.data = data

    def hash(self):
        return self._hash(self.data, 0)

    def _hash(self, data, index):
        if index < len(data):
            return (ord(data[index]) + self._hash(data, index + 1)) % 1000000
        return 0

class CipherSimulator:

    def __init__(self, key):
        self.key = key

    def encrypt(self, data):
        return self._encrypt(data, 0)

    def _encrypt(self, data, index):
        if index < len(data):
            return (ord(data[index]) + self.key + self._encrypt(data, index + 1)) % 256
        return 0

class RecurringProcess:

    def __init__(self, data, key):
        self.hash_sim = HashSimulator(data)
        self.cipher_sim = CipherSimulator(key)

    def process(self):
        while True:
            hash_value = self.hash_sim.hash()
            encrypted_data = self.cipher_sim.encrypt(chr(hash_value))
            self.hash_sim = HashSimulator(chr(encrypted_data))
            self.cipher_sim = CipherSimulator(self.cipher_sim.encrypt(str(hash_value)))

def main():
    initial_data = 'start'
    initial_key = 7
    process = RecurringProcess(initial_data, initial_key)
    process.process()
main()