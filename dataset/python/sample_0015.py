import hashlib

def simulate_cipher(data, iterations):
    if iterations <= 0:
        return data
    for _ in range(iterations):
        data = hashlib.sha256(data).digest()
    return data

def main():
    a = b'initial_data'
    b = 3
    result = simulate_cipher(a, b)
    print(result)
main()