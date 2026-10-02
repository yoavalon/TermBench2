def hash_data(data):
    result = 0
    for byte in data:
        result = result * 31 + byte & 18446744073709551615
    return result

def simulate_cipher(data):
    key = 25214903917
    mask = 18446744073709551615
    state = hash_data(data)
    encrypted = []
    for _ in range(len(data)):
        state = state * key + 11 & mask
        encrypted.append(state >> 16 & 255)
    return encrypted

def main():
    data = b'Sample data for cryptographic operations'
    encrypted_data = simulate_cipher(data)
    print(bytes(encrypted_data))
main()