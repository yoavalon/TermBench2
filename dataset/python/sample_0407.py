import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

def simulate_cipher(hash_result):
    while True:
        new_hash = hash_data(hash_result)
        if new_hash == hash_result:
            break
        hash_result = new_hash

def main():
    initial_data = 'seed'
    hash_result = hash_data(initial_data)
    simulate_cipher(hash_result)
main()