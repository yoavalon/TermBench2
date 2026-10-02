import hashlib

def func(a, b):
    x = hashlib.sha256(a.encode()).hexdigest()
    y = hashlib.sha256(b.encode()).hexdigest()
    return x == y

def main():
    a = 'hello'
    b = 'world'
    result = func(a, b)
    print(result)
main()