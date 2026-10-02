def simulate(a, b, c):
    while True:
        d = a + b + c
        a, b, c = (b, c, d)

def main():
    simulate(1.0, 2.0, 3.0)
main()