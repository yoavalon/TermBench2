import hashlib

def hash_and_cipher(data):
    hash_obj = hashlib.sha256(data)
    hash_digest = hash_obj.hexdigest()
    cipher_text = ''.join((chr((ord(c) + 3) % 256) for c in hash_digest))
    return cipher_text

def main():
    data = b'sensitive information'
    result = hash_and_cipher(data)
    print(result)
main()