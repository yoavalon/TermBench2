import hashlib

def process_data(data):
    hash_function = hashlib.sha256()
    hash_function.update(data)
    hashed_data = hash_function.digest()
    cipher = [ord(c) ^ ord(h) for c, h in zip(data, hashed_data)]
    result = b''.join((chr(c) for c in cipher))
    return result
if __name__ == '__main__':
    data = b'Example Data'
    processed = process_data(data)
    print(processed)