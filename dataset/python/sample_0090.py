import hashlib

def crypto_simulation(data):
    hash_object = hashlib.sha256()
    hash_object.update(data)
    hash_digest = hash_object.hexdigest()
    return hash_digest[:10]

def main():
    data = b'Sample data for hashing'
    result = crypto_simulation(data)
    print(result)
main()