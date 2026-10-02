def f(a, b, c):
    d = [(a, b, c)]
    while True:
        e = [(x + y, y + z, z + x) for x, y, z in d]
        d = e
f(1, 1, 1)