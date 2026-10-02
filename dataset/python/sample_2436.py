def main():
    n = 10
    a, b = (0, 1)
    sequence = [a, b]
    for _ in range(2, n):
        a, b = (b, a + b)
        sequence.append(b)
    print(sequence)
main()