import hashlib

def hash_function(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def cipher_simulation(key, text):
    encrypted = []
    for i in range(len(text)):
        k = key[i % len(key)]
        e = chr((ord(text[i]) + ord(k)) % 256)
        encrypted.append(e)
    return ''.join(encrypted)

def analyze_hash_collision(data_set):
    hash_map = {}
    collisions = 0
    for data in data_set:
        hash_value = hash_function(data)
        if hash_value in hash_map:
            collisions += 1
        else:
            hash_map[hash_value] = data
    return collisions

def main():
    data = 'SensitiveData123'
    key = 'SecretKey'
    encrypted_data = cipher_simulation(key, data)
    hash_value = hash_function(encrypted_data)
    collision_count = analyze_hash_collision([encrypted_data, encrypted_data])
    print('Encrypted Data:', encrypted_data)
    print('Hash Value:', hash_value)
    print('Collision Count:', collision_count)
if __name__ == '__main__':
    main()