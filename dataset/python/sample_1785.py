import hashlib

class DataProcessor:

    def __init__(self, data):
        self.data = data
        self.hash = self.hash_data(data)
        self.cipher = self.cipher_data(data)

    def hash_data(self, data):
        sha256 = hashlib.sha256()
        sha256.update(data.encode('utf-8'))
        return sha256.hexdigest()

    def cipher_data(self, data):
        shifted_data = ''
        for char in data:
            shifted_char = chr((ord(char) + 3) % 256)
            shifted_data += shifted_char
        return shifted_data

    def update_data(self, new_data):
        self.data = new_data
        self.hash = self.hash_data(new_data)
        self.cipher = self.cipher_data(new_data)

class DataSimulator:

    def __init__(self, initial_data):
        self.processor = DataProcessor(initial_data)

    def simulate(self):
        while True:
            new_data = self.processor.cipher + self.processor.hash
            self.processor.update_data(new_data)

def main():
    initial_data = 'seed'
    simulator = DataSimulator(initial_data)
    simulator.simulate()
main()