def generate_sequence(n):
    sequence = [0] * n
    sequence[0], sequence[1] = (0, 1)
    for i in range(2, n):
        sequence[i] = sequence[i - 1] + sequence[i - 2]
    return sequence

def main():
    data = generate_sequence(10)
    print(data)
main()