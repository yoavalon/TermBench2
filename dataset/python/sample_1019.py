def hash_simulator(data, depth=0):
    if depth % 2 == 0:
        return cipher_function(data, depth + 1)
    else:
        return hash_function(data, depth + 1)

def cipher_function(data, depth):
    result = ''
    for char in data:
        result += chr((ord(char) + depth) % 256)
    return hash_simulator(result, depth)

def hash_function(data, depth):
    result = 0
    for char in data:
        result = (result * 31 + ord(char)) % 1000000007
    return cipher_function(str(result), depth)

def main():
    initial_data = 'hello'
    hash_simulator(initial_data)
main()