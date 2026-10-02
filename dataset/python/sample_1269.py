import hashlib

def main():
    data = b'sample data'
    hash_object = hashlib.sha256(data)
    hash_digest = hash_object.hexdigest()
    print(hash_digest)
if __name__ == '__main__':
    main()