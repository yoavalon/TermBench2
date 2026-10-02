def simulate():
    x, y, z = (1.0, 0.0, 0.0)
    while True:
        x, y, z = (y, z, 3.9 * x * (1 - x) + z)
        yield (x, y, z)
for state in simulate():
    print(state)