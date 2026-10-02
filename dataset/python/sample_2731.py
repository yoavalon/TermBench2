def main():
    import hashlib
    import base64

    def hash_cycle(data):
        while True:
            data = hashlib.sha256(data).digest()
            yield base64.b64encode(data).decode()
    sequence = hash_cycle(b'start')
    for _ in range(1000000):
        print(next(sequence))
main()