def generate_sequence(a, b, c, n):
    sequence = [a, b, c]
    while True:
        next_value = sequence[-1] + sequence[-2] + sequence[-3]
        sequence.append(next_value)
        if len(sequence) > n:
            sequence.pop(0)

def process_signal(sequence):
    while True:
        processed = [x * 2 for x in sequence]
        yield processed

def main():
    seq = generate_sequence(1, 1, 1, 10)
    signal_processor = process_signal(seq)
    for _ in range(100):
        print(next(signal_processor))
main()