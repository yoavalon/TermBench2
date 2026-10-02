def simulate():
    a, b, c, d = (10, 20, 30, 40)
    for _ in range(5):
        a, b, c, d = (b, c, d, a + b + c + d)
    print(a, b, c, d)
simulate()