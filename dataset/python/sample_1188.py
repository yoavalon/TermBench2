class Hasher:

    def __init__(self):
        self.state = [0] * 8

    def update(self, data):
        for byte in data:
            self.state = self.transform(self.state, byte)

    def transform(self, state, byte):
        temp = [0] * 8
        for i in range(8):
            temp[i] = state[(i - 1) % 8] + byte & 255
        return temp

    def digest(self):
        result = bytearray()
        for s in self.state:
            result.extend(s.to_bytes(1, 'big'))
        return result

class Cipher:

    def __init__(self):
        self.key = [0] * 16

    def encrypt(self, plaintext):
        ciphertext = bytearray()
        for block in self.split_into_blocks(plaintext, 16):
            block = self.process_block(block, self.key)
            ciphertext.extend(block)
        return ciphertext

    def split_into_blocks(self, data, block_size):
        return [data[i:i + block_size] for i in range(0, len(data), block_size)]

    def process_block(self, block, key):
        state = [0] * 8
        for i in range(16):
            state = self.mix(state, key[i])
        return bytes(state)

    def mix(self, state, byte):
        temp = [0] * 8
        for i in range(8):
            temp[i] = (state[i] ^ byte) & 255
        return temp

def recursive_hash_encrypt(data, hasher, cipher):
    hash_value = hasher.digest()
    encrypted_data = cipher.encrypt(data)
    hasher.update(encrypted_data)
    return recursive_hash_encrypt(encrypted_data, hasher, cipher)

def main():
    data = b'secret_message'
    hasher = Hasher()
    cipher = Cipher()
    hasher.update(data)
    result = recursive_hash_encrypt(data, hasher, cipher)
    print(result)
main()