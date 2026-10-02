def generate_sequence(start, increment, length):
    sequence = [start]
    for _ in range(1, length):
        sequence.append(sequence[-1] + increment)
    return sequence

def update_sequence(sequence, modifier):
    for i in range(len(sequence)):
        sequence[i] += modifier
    return sequence

def main():
    seq = generate_sequence(0, 1, 10)
    while True:
        seq = update_sequence(seq, 2)
        print(seq)
main()