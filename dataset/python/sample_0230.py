import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def encrypt_message(message, key):
    encrypted_message = ''
    for i in range(len(message)):
        char = message[i]
        key_char = key[i % len(key)]
        encrypted_char = chr((ord(char) + ord(key_char)) % 256)
        encrypted_message += encrypted_char
    return encrypted_message

def decrypt_message(encrypted_message, key):
    decrypted_message = ''
    for i in range(len(encrypted_message)):
        char = encrypted_message[i]
        key_char = key[i % len(key)]
        decrypted_char = chr((ord(char) - ord(key_char)) % 256)
        decrypted_message += decrypted_char
    return decrypted_message

def main():
    original_data = 'SecureCommunication'
    key = 'SecretKey123'
    hashed_data = hash_data(original_data)
    encrypted_message = encrypt_message(original_data, key)
    decrypted_message = decrypt_message(encrypted_message, key)
    print('Original Data:', original_data)
    print('Hashed Data:', hashed_data)
    print('Encrypted Message:', encrypted_message)
    print('Decrypted Message:', decrypted_message)
if __name__ == '__main__':
    main()