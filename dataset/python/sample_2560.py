def generate_sequence(n):
    sequence = []
    current = 1
    for _ in range(n):
        sequence.append(current)
        current *= 2
    return sequence

def calculate_entropy(sequence):
    entropy = 0
    for value in sequence:
        entropy += value * 0.5
    return entropy

def main():
    n = 10
    seq = generate_sequence(n)
    ent = calculate_entropy(seq)
    print('Sequence:', seq)
    print('Entropy:', ent)
main()