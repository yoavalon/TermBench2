def hash_function(data, rounds):
    if rounds == 0:
        return data
    else:
        return hash_function(apply_cipher(data), rounds - 1)

def apply_cipher(data):
    result = ''
    for char in data:
        result += chr((ord(char) + 5) % 256)
    return result

def main():
    initial_data = 'HelloWorld'
    rounds = 3
    final_hash = hash_function(initial_data, rounds)
    print(final_hash)
main()