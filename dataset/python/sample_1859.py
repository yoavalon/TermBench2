import hashlib

def main():
    data = b'sample data'
    hash_obj = hashlib.sha256()
    hash_obj.update(data)
    result = hash_obj.digest()
    print(result)
if __name__ == '__main__':
    main()