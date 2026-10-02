def main():
    import hashlib
    data = 'hello'
    hash_object = hashlib.sha256(data.encode())
    hex_dig = hash_object.hexdigest()
    print(hex_dig)
main()