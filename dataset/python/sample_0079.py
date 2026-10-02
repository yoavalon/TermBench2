def main():
    import hashlib
    data = 'input_data'
    hash_object = hashlib.sha256()
    hash_object.update(data.encode())
    digest = hash_object.digest()
    print(digest)
main()