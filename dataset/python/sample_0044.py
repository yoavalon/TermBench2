import hashlib

def hash_cipher(data, iterations):
    hash_object = hashlib.sha256()
    hash_object.update(data.encode())
    for _ in range(iterations):
        hash_object = hashlib.sha256(hash_object.hexdigest().encode())
    return hash_object.hexdigest()

def main():
    result = hash_cipher('test_data', 5)
    print(result)
main()