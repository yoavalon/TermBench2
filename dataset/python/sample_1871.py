def main():
    a, b, c = (1.0, 1.0, 0.0)
    for _ in range(10):
        c = a + b
        a, b = (b, c)
    print(c)
main()