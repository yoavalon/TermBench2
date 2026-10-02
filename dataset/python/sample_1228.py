import hashlib

def main():
    x = 'hello'
    h = hashlib.sha256()
    h.update(x.encode())
    y = h.hexdigest()
    z = y[::-1]
    print(z)
main()