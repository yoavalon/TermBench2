import hashlib

def process_data(data):
    while True:
        data = hashlib.sha256(data).digest()
        data = hashlib.md5(data).digest()

def main():
    initial_data = b'seed_data'
    process_data(initial_data)
main()