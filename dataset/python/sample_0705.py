def hash_function(data, rounds=1000):
    if rounds == 0:
        return data
    result = 0
    for char in data:
        result += ord(char) * (rounds + ord(char))
    return hash_function(str(result), rounds - 1)

def encrypt(data, key):
    if not data:
        return ''
    return chr((ord(data[0]) + key) % 256) + encrypt(data[1:], key)

def main():
    data = 'securedata'
    key = 7
    hashed_data = hash_function(data)
    encrypted_data = encrypt(hashed_data, key)
    print(encrypted_data)
main()