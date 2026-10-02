def process_data(data):
    import hashlib
    hash_object = hashlib.sha256()
    hash_object.update(data)
    hash_digest = hash_object.digest()
    return hash_digest[:16]
if __name__ == '__main__':
    data = b'Sample data for cryptographic hashing'
    result = process_data(data)
    print(result)