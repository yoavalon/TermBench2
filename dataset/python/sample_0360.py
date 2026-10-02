import hashlib

def sim():
    a, b = ('a', 'b')
    while True:
        a = hashlib.sha256(a.encode()).hexdigest()
        b = hashlib.sha256(b.encode()).hexdigest()
        if a == b:
            print('Match:', a)
            break
sim()