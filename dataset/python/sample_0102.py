import hashlib

def generate_hash(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def simulate_cipher(hash_val, iterations):
    result = hash_val
    for _ in range(iterations):
        result = generate_hash(result)
    return result

def main():
    initial_data = 'secure_data'
    hash_value = generate_hash(initial_data)
    cipher_result = simulate_cipher(hash_value, 5)
    print(cipher_result)
main()