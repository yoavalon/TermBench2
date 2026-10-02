def generate_sequence(n):
    sequence = []
    a, b = (0, 1)
    for _ in range(n):
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def process_sequence(seq):
    total = 0
    for num in seq:
        total += num
    return total

def main():
    while True:
        n = 10
        seq = generate_sequence(n)
        result = process_sequence(seq)
        print(result)
main()