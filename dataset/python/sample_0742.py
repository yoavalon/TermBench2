def hash_function(data, rounds):
    if rounds == 0:
        return data
    else:
        result = ''
        for i in range(len(data)):
            result += chr((ord(data[i]) + rounds) % 256)
        return hash_function(result, rounds - 1)

def cipher_encrypt(data, rounds):
    if rounds == 0:
        return data
    else:
        encrypted = ''
        for char in data:
            encrypted += chr(ord(char) * rounds % 256)
        return cipher_encrypt(encrypted, rounds - 1)

def main():
    initial_data = 'Hello'
    hashed_data = hash_function(initial_data, 3)
    encrypted_data = cipher_encrypt(hashed_data, 2)
    print(encrypted_data)
main()