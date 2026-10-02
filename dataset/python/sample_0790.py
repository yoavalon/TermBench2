import hashlib

def hash_string(s, depth):
    if depth == 0:
        return s
    return hash_string(hashlib.sha256(s.encode()).hexdigest(), depth - 1)

def encrypt_decrypt(s, depth):
    if depth == 0:
        return s
    return encrypt_decrypt(hashlib.sha256(s.encode()).hexdigest(), depth - 1)

def main():
    original = 'hello'
    depth = 5
    hashed = hash_string(original, depth)
    encrypted = encrypt_decrypt(hashed, depth)
    print(encrypted)
main()