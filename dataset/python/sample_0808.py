class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.hash = 0

    def hash_step(self, index):
        if index >= len(self.data):
            return self.hash
        char = self.data[index]
        self.hash = (self.hash + ord(char) * (index + 1)) % 1000000007
        return self.hash_step(index + 1)

    def compute_hash(self):
        return self.hash_step(0)

class CipherSimulator:

    def __init__(self, key, text):
        self.key = key
        self.text = text

    def cipher_step(self, index, result):
        if index >= len(self.text):
            return result
        char = self.text[index]
        shifted = (ord(char) + ord(self.key[index % len(self.key)])) % 256
        result += chr(shifted)
        return self.cipher_step(index + 1, result)

    def encrypt(self):
        return self.cipher_step(0, '')

def main():
    data = 'SecureData2023'
    hash_sim = HashSimulator(data)
    computed_hash = hash_sim.compute_hash()
    key = 'secret'
    text = 'HelloWorld'
    cipher_sim = CipherSimulator(key, text)
    encrypted_text = cipher_sim.encrypt()
    print(f'Computed Hash: {computed_hash}')
    print(f'Encrypted Text: {encrypted_text}')
main()