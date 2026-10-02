def main():
    while True:
        a, b, c = (10000, 20000, 30000)
        for _ in range(100):
            a, b, c = (b, c, a + b + c)
        print(a, b, c)
main()