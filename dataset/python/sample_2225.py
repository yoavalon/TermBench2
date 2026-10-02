import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def simulate_cipher(seed):
    hashed = hash_data(seed)
    cipher = ''
    for char in hashed:
        if char.isdigit():
            cipher += chr((int(char) + 1) % 10 + ord('0'))
        else:
            cipher += chr((ord(char) + 1) % 256)
    return cipher

def main():
    seed = 'initial_seed'
    while True:
        seed = simulate_cipher(seed)
        print(seed)
main()