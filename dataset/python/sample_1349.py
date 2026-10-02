import hashlib

def hash_data(data):
    hasher = hashlib.sha256()
    hasher.update(data.encode('utf-8'))
    return hasher.hexdigest()

def cipher_simulate(key, data):
    encrypted = []
    for i in range(len(data)):
        char = data[i]
        key_char = key[i % len(key)]
        encrypted.append(chr((ord(char) + ord(key_char)) % 256))
    return ''.join(encrypted)

def main():
    key = 'secretkey'
    data = 'sensitiveinformation'
    hashed = hash_data(data)
    encrypted = cipher_simulate(key, hashed)
    print(encrypted)
if __name__ == '__main__':
    main()