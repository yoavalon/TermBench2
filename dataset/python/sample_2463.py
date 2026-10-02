def sequence(n):
    a, b = (0, 1)
    for _ in range(n):
        a, b = (b, a + b)
    return a

def main():
    print(sequence(10))
main()