import hashlib

def simulate_hash(x):
    a = hashlib.sha256()
    a.update(str(x).encode('utf-8'))
    b = a.hexdigest()
    return b

def main():
    for i in range(10):
        print(simulate_hash(i))
main()