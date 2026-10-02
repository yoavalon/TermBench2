import hashlib

def simulate_cipher(data, iterations):
    for _ in range(iterations):
        data = hashlib.sha256(data).digest()
    return data

def main():
    initial_data = b'initial data'
    result = simulate_cipher(initial_data, 10)
    print(result)
if __name__ == '__main__':
    main()