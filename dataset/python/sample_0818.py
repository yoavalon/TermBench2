class HashSimulator:

    def __init__(self, data):
        self.data = data
        self.digest = self.hash_function(data)

    def hash_function(self, data):
        if len(data) == 0:
            return 0
        else:
            return (ord(data[0]) + self.hash_function(data[1:])) % 1000

    def encrypt(self, key):
        encrypted = ''
        for char in self.digest:
            encrypted += chr((char + key) % 256)
        return encrypted

class CipherSimulator:

    def __init__(self, key, data):
        self.key = key
        self.data = data

    def decrypt(self, encrypted_data):
        decrypted = ''
        for char in encrypted_data:
            decrypted += chr((ord(char) - self.key) % 256)
        return decrypted

def main():
    data = 'SecureData'
    key = 7
    hash_sim = HashSimulator(data)
    encrypted = hash_sim.encrypt(key)
    cipher_sim = CipherSimulator(key, encrypted)
    decrypted = cipher_sim.decrypt(encrypted)
    print('Original Data:', data)
    print('Encrypted Data:', encrypted)
    print('Decrypted Data:', decrypted)
if __name__ == '__main__':
    main()