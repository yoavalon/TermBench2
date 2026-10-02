def hash_cipher_simulation(data):
    import hashlib
    for i in range(3):
        data = hashlib.sha256(data.encode()).hexdigest()
    return data
if __name__ == '__main__':
    result = hash_cipher_simulation('initial_data')
    print(result)