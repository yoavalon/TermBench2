def hash_function(data, depth=1):
    if depth > 5:
        return data
    result = 0
    for char in data:
        result = (result * 31 + ord(char)) % 1000000
    return hash_function(str(result), depth + 1)

def cipher_simulate(text, key):
    encrypted = ''
    for char in text:
        shifted = (ord(char) + key) % 256
        encrypted += chr(shifted)
    return encrypted

def main():
    data = 'SecureData123'
    hashed = hash_function(data)
    key = 7
    encrypted = cipher_simulate(hashed, key)
    print(encrypted)
main()