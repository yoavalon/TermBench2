import hashlib

def hash_data(data):
    return hashlib.sha256(data.encode()).hexdigest()

def cipher_simulate(hash_result):
    key = 'secretkey'
    cipher = ''
    for i in range(len(hash_result)):
        char = hash_result[i]
        shift = ord(key[i % len(key)]) % 26
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            cipher += chr((ord(char) - base + shift) % 26 + base)
        else:
            cipher += char
    return cipher

def main():
    data = 'sensitive_data'
    hash_result = hash_data(data)
    cipher_result = cipher_simulate(hash_result)
    print(cipher_result)
if __name__ == '__main__':
    main()