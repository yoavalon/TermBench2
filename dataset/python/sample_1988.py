import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def simulate_cipher(hash_value):
    result = ''
    for char in hash_value:
        if char.isdigit():
            result += str((int(char) + 5) % 10)
        else:
            result += chr((ord(char) + 3) % 256)
    return result

def main():
    data = 'securedata'
    hashed = hash_data(data)
    ciphered = simulate_cipher(hashed)
    print(ciphered)
if __name__ == '__main__':
    main()