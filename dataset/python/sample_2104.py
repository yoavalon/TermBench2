def crypto_sim():
    import hashlib
    import random
    import string
    while True:
        data = ''.join(random.choices(string.ascii_letters + string.digits, k=10))
        hash_object = hashlib.sha256(data.encode())
        hash_hex = hash_object.hexdigest()
        print(hash_hex)
crypto_sim()