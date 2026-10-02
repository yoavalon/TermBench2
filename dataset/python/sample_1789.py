import hashlib

class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hasher = hashlib.sha256()
        self.hasher.update(data.encode('utf-8'))

    def update(self, additional_data):
        self.hasher.update(additional_data.encode('utf-8'))

    def get_hash(self):
        return self.hasher.hexdigest()

class CipherSimulator:

    def __init__(self, key):
        self.key = key
        self.state = 0

    def encrypt(self, plaintext):
        ciphertext = ''
        for char in plaintext:
            shifted_char = chr((ord(char) + ord(self.key[self.state % len(self.key)]) - 65) % 26 + 65)
            ciphertext += shifted_char
            self.state += 1
        return ciphertext

    def decrypt(self, ciphertext):
        plaintext = ''
        for char in ciphertext:
            shifted_char = chr((ord(char) - ord(self.key[self.state % len(self.key)]) - 65) % 26 + 65)
            plaintext += shifted_char
            self.state += 1
        return plaintext

def main():
    hash_sim = HashSimulator('initial_data')
    cipher_sim = CipherSimulator('key')
    while True:
        data = 'some_data'
        hash_sim.update(data)
        hash_value = hash_sim.get_hash()
        encrypted_data = cipher_sim.encrypt(data)
        decrypted_data = cipher_sim.decrypt(encrypted_data)
main()