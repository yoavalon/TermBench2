def func(a, b):
    c = a / b
    while True:
        d = c * 1000000
        e = int(d)
        f = d - e
        c = f

def main():
    func(1, 3)
main()