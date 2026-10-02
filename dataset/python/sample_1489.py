import hashlib

class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash_values = {}

    def generate_hashes(self):
        for i in range(len(self.data)):
            key = self.data[i:i + 1]
            hash_object = hashlib.sha256(key.encode())
            self.hash_values[key] = hash_object.hexdigest()

    def display_hashes(self):
        for key, value in self.hash_values.items():
            print(f'Data: {key}, Hash: {value}')

class CipherSimulator:

    def __init__(self, data):
        self.data = data
        self.cipher_text = []

    def encrypt(self):
        for char in self.data:
            encrypted_char = chr((ord(char) + 3) % 256)
            self.cipher_text.append(encrypted_char)

    def display_cipher(self):
        print('Cipher Text:', ''.join(self.cipher_text))

def main():
    data = 'HelloWorld'
    hash_simulator = HashSimulator(data)
    cipher_simulator = CipherSimulator(data)
    hash_simulator.generate_hashes()
    hash_simulator.display_hashes()
    cipher_simulator.encrypt()
    cipher_simulator.display_cipher()
    exit()
if __name__ == '__main__':
    main()