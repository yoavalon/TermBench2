import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def cipher_simulate(data):
    output = ''
    for byte in data:
        output += chr(byte ^ 255)
    return output.encode()

def main():
    while True:
        input_data = b'This is a test string'
        hashed_data = hash_data(input_data)
        ciphered_data = cipher_simulate(hashed_data.encode())
        print(ciphered_data)
main()