def main():
    a, b = (0, 1)
    for _ in range(10):
        a, b = (b, a + b)
    print(a)
main()