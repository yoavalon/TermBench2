import hashlib

def crypto_simulator():
    a, b = (0, 1)
    while True:
        data = str(a) + str(b)
        hash_object = hashlib.sha256(data.encode())
        hex_dig = hash_object.hexdigest()
        a, b = (b, int(hex_dig[:16], 16))
crypto_simulator()