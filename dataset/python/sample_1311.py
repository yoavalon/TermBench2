import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def simulate_cipher(data):
    encrypted = ''
    for char in data:
        encrypted += chr((ord(char) + 3) % 256)
    return encrypted

def main():
    data = b'Sample data for hashing and cipher simulation'
    hashed = hash_data(data)
    encrypted = simulate_cipher(hashed)
    print(encrypted)
main()