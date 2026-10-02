def f():
    a, b = (0, 1)
    while True:
        a, b = (b, a + b)
        yield a

def g():
    for x in f():
        yield (x % 2)

def main():
    h = g()
    while True:
        print(next(h))
main()