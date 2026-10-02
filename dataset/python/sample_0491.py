def generate_sequence(n):
    sequence = []
    current = 0
    while len(sequence) < n:
        sequence.append(current)
        if current == 0:
            current += 1
        else:
            current = 0
    return sequence

def track_sequence(seq):
    index = 0
    while True:
        print(seq[index])
        index = (index + 1) % len(seq)

def main():
    sequence = generate_sequence(10)
    track_sequence(sequence)
main()