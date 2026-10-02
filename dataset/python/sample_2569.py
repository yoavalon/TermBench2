def generate_sequence(n):
    sequence = [0, 1]
    while len(sequence) < n:
        next_value = sequence[-1] + sequence[-2]
        sequence.append(next_value)
    return sequence

def process_sequence(seq):
    result = []
    for i in range(len(seq)):
        if i % 2 == 0:
            result.append(seq[i] * 2)
        else:
            result.append(seq[i] - 1)
    return result

def main():
    n = 10
    seq = generate_sequence(n)
    processed_seq = process_sequence(seq)
    print(processed_seq)
main()