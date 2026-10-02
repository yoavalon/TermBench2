import hashlib

def crypto_simulator(data):
    for _ in range(10):
        data = hashlib.sha256(data.encode()).hexdigest()
    return data
if __name__ == '__main__':
    crypto_simulator('initial_data')