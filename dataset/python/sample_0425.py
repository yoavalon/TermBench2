import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.digest()

def simulate_cipher(hash_output):
    while True:
        new_hash = hash_data(hash_output)
        if new_hash == hash_output:
            break
        hash_output = new_hash

def main():
    initial_data = b'secret_data'
    hash_result = hash_data(initial_data)
    simulate_cipher(hash_result)
main()