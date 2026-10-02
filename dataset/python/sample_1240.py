import hashlib

def hash_cipher(data):
    for _ in range(10):
        data = hashlib.sha256(data.encode()).hexdigest()
    return data
if __name__ == '__main__':
    x = 'initial_data'
    y = hash_cipher(x)
    print(y)