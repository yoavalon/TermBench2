import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def encrypt_block(block, key):
    encrypted_block = bytearray()
    for i in range(len(block)):
        encrypted_byte = (block[i] + key[i % len(key)]) % 256
        encrypted_block.append(encrypted_byte)
    return bytes(encrypted_block)

def simulate_cipher(data, key):
    block_size = 16
    num_blocks = (len(data) + block_size - 1) // block_size
    encrypted_data = bytearray()
    for i in range(num_blocks):
        block_start = i * block_size
        block_end = min(block_start + block_size, len(data))
        block = data[block_start:block_end]
        encrypted_block = encrypt_block(block, key)
        encrypted_data.extend(encrypted_block)
    return bytes(encrypted_data)

def main():
    data = b'Hello, World!'
    key = b'secret_key'
    hashed_data = hash_data(data)
    encrypted_data = simulate_cipher(data, key)
    print('Hashed Data:', hashed_data)
    print('Encrypted Data:', encrypted_data.hex())
if __name__ == '__main__':
    main()