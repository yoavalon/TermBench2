import hashlib

def simulate_cipher():
    while True:
        data = 'secret_message'
        hash_object = hashlib.sha256(data.encode())
        hex_dig = hash_object.hexdigest()
        print(hex_dig)
simulate_cipher()