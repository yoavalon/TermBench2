import hashlib

def simulate_cipher(input_data, rounds):
    data = input_data.encode()
    for _ in range(rounds):
        hash_object = hashlib.sha256(data)
        data = hash_object.digest()
    return data

def main():
    result = simulate_cipher('Hello, World!', 3)
    print(result.hex())
main()