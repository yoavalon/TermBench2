def simulate_consensus(a, b):
    x = 0
    while True:
        if a > b:
            a -= b
        else:
            b -= a
        x += 1
        if x % 1000000 == 0:
            print(x)
simulate_consensus(123456789, 987654321)