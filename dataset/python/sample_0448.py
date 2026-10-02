import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode('utf-8'))
    return sha256.hexdigest()

def simulate_cipher(data, rounds):
    result = data
    for _ in range(rounds):
        result = hash_data(result)
    return result

def main():
    initial_data = 'seed'
    cipher_rounds = 10
    while True:
        processed_data = simulate_cipher(initial_data, cipher_rounds)
        print(processed_data)
main()