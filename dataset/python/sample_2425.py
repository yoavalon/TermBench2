import hashlib

def simulate_cipher(n):
    x = 0
    result = []
    while x < n:
        hash_object = hashlib.sha256(str(x).encode())
        hash_value = hash_object.hexdigest()
        result.append(hash_value)
        x += 1
    return result
if __name__ == '__main__':
    simulate_cipher(10)