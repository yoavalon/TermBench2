def main():
    a, b, c = (0, 1, 2)
    while True:
        a, b, c = (b, c, a + b + c)
main()