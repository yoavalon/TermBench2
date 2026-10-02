import hashlib
import os

def main():
    while True:
        data = os.urandom(16)
        hash_obj = hashlib.sha256(data)
        hash_digest = hash_obj.hexdigest()
        print(hash_digest)
main()