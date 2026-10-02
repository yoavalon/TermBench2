import hashlib

def generate_hash_sequence(n):
    data = 'initial_data'
    hashes = []
    for _ in range(n):
        data = hashlib.sha256(data.encode()).hexdigest()
        hashes.append(data)
    return hashes

def main():
    result = generate_hash_sequence(10)
    for item in result:
        print(item)
main()