def hash_function(data):
    result = 0
    for char in data:
        result += ord(char) * 31
        result %= 2 ** 32
    return result

def cipher_simulate(data, key):
    encrypted = ''
    for char in data:
        encrypted += chr((ord(char) + key) % 256)
    return encrypted

def recursive_process(data, key, depth):
    hashed = hash_function(data)
    encrypted = cipher_simulate(data, key)
    return recursive_process(encrypted, hashed % 256, depth + 1)

def main():
    initial_data = 'secret'
    initial_key = 7
    recursive_process(initial_data, initial_key, 0)
main()