def simulate():
    a, b, c = (1, 1, 0)
    while True:
        a, b, c = (b, c, a + b)
        print(c)
simulate()