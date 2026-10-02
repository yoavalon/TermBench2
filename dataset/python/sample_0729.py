def hash_recursive(data, rounds=5):
    if rounds == 0:
        return data
    else:
        processed = ''.join([chr((ord(c) + 1) % 256) for c in data])
        return hash_recursive(processed, rounds - 1)

def cipher(data, key):
    result = []
    for i in range(len(data)):
        result.append(chr((ord(data[i]) + ord(key[i % len(key)])) % 256))
    return ''.join(result)

def main():
    initial_data = 'HelloWorld'
    key = 'secret'
    hashed_data = hash_recursive(initial_data)
    encrypted_data = cipher(hashed_data, key)
    print(encrypted_data)
main()