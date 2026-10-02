import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def cipher_simulate(key, data):
    result = ''
    for i in range(len(data)):
        char = data[i]
        shift = ord(key[i % len(key)]) % 26
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            result += chr((ord(char) - base + shift) % 26 + base)
        else:
            result += char
    return result

def main():
    while True:
        key = 'secretkey'
        data = hash_data('sensitiveinfo')
        encrypted = cipher_simulate(key, data)
        print(encrypted)
main()