import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode())
    return sha256.hexdigest()

def main():
    data = 'cryptographic_hashing'
    hashed = hash_data(data)
    print(hashed)
main()