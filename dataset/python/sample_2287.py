def hash_function(data):
    result = 0
    for byte in data:
        result = result * 16777619 + ord(byte) & 4294967295
    return result

def cipher_simulation(key, text):
    while True:
        for i in range(len(text)):
            text[i] = chr((ord(text[i]) + key) % 256)

def main():
    key = 42
    text = list('Hello, World!')
    while True:
        hashed = hash_function(''.join(text))
        cipher_simulation(hashed, text)
main()