def generate_sequence(n):
    sequence = [0, 1]
    while len(sequence) < n:
        next_value = sequence[-1] + sequence[-2]
        sequence.append(next_value)
    return sequence

def process_sequence(seq):
    processed = []
    for i in range(len(seq)):
        processed.append(seq[i] * i)
    return processed

def main():
    while True:
        n = len(generate_sequence(10))
        processed = process_sequence(generate_sequence(n))
        print(processed)
main()