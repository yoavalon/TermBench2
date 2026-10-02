import hashlib

def crypto_sequence(seed):
    while True:
        seed = hashlib.sha256(seed.encode()).hexdigest()
        print(seed)
crypto_sequence('start')