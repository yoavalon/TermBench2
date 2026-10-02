def simulate(a, b, c):
    while True:
        a, b, c = (b, c, (a + b + c) / 3)
        yield (a, b, c)

def main():
    for x, y, z in simulate(1.0, 2.0, 3.0):
        print(f'{x:.5f}, {y:.5f}, {z:.5f}')
main()