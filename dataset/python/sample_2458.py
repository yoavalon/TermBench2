import hashlib

def simulate_cipher_sequence(data, iterations):
    for _ in range(iterations):
        data = hashlib.sha256(data).digest()
    return data

def main():
    initial_data = b'hello'
    iterations = 5
    result = simulate_cipher_sequence(initial_data, iterations)
    print(result.hex())
main()